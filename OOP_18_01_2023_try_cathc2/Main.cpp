#include<iostream>
#include<vector>
#include<string>
// Наследование шаблонных классов
template<class T>
class Shape {
public:
	Shape(T width, T hight) : _width(width), _hight(hight) {
		std::cout << "construtor Shape" << '\n';
	}
		T calculateSquare(){
		return _width * _hight;
	}
private:
	T _width;
	T _hight;
};

template<class T>
class Square : public Shape<T> {
public:
	Square(T width, T higth) : Shape<T>(width, higth), _width(width){
		std::cout << "constructor Square" << '\n';
	}

	T calculateSquare() {
		return _width * _width;  
	}
private:
	T _width;
};

// Вариабельные шаблоны класса - Variadic Templatet

template<typename ... Args>// void f(Args ... args);
class MyClass {
public:
	void printAll(Args...args) {
		std::cout << sizeof...(args) << '\n';
		(std::cout << ... << args) << '\n';
	}

};
//template<typename ... Args>
//auto sum_all(Args ... args) { return (args + ...); } // (p1 op (p2 op(...(pN-1 op pN)...)
//template<typename ... Args>
//void print_all(Args...args) {(cout << ... << args) << endl }

int main() {

	MyClass<int, double, float, std::string> a;
	int x = 5;
	double y = 3.4;
	float z = 11.2f;
	std::string str = "hello world!";
	a.printAll(x, y, z, str);

	/*Square<int> s(5, 4);
	std::cout << s.calculateSquare() << '\n';
	std::cout << s.Shape<int>::calculateSquare();*/


	
	return 0;
}