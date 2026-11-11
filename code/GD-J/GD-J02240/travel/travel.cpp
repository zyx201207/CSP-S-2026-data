#include <iostream>
#include <cstdio>
using namespace std;
int a, b, d, e;
char c, f;
bool x, y, z, w;
void inpt(int &n){
	char x, y;
	cin >> x >> y;
	n = (x-'0')*10 + (y-'0');
	//cout<<n;
	return;
}
bool lr(char c){
	if(c == 'A' || c == 'B' || c == 'C')
		return 0;
	else return 1;
}
bool nr(char c, char f){
	if(c == 'C' && f == 'A')
		return 0;
	if(c == 'A' && f == 'C')
		return 0;
	return 1;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	inpt(a);
	inpt(b);
	cin >> c;
	inpt(d);
	inpt(e);
	cin >> f;
	//cout<<a<<b<<c<<d<<e<<f;
	x = (a == d);
	if(x){
		y = (b == e);
	}
	if(y){
		z = (lr(c) == lr(f));
	}
	if(z){
		w = nr(c, f);
	}
	cout <<x <<y <<z <<w;
	return 0;
}
