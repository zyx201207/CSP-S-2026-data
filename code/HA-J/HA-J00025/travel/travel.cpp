//freopen!!
//freopen±ğÍüÉ¾×¢ÊÍ 
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2, b1, b2;
	char s1, s2;
	string xx;
	cin >> xx;
	a1 = (xx[0] - '0') * 10 + (xx[1] - '0');
	cin >> xx;
	a2 = (xx[0] - '0') * 10 + (xx[1] - '0');
	s1 = xx[2];
	cin >> xx;
	b1 = (xx[0] - '0') * 10 + (xx[1] - '0');
	cin >> xx;
	b2 = (xx[0] - '0') * 10 + (xx[1] - '0');
	s2 = xx[2];
	bool p1 = 0, p2 = 0, p3 = 0;
	if(a1 == b1){
		cout << 1;
		p1 = 1;
	}else cout << 0;
	if(p1 && a2 == b2){
		cout << 1;
		p2 = 1;
	}else cout << 0;
	if(p1 && p2 && ((s1 <= 'C' && s2 <= 'C') || (s1 >= 'D' && s2 >= 'D'))){
		cout << 1;
		p3 = 1;
	}else cout << 0;
	if(p1 && p2 && p3 && (abs((int)(s1 - s2)) == 1)){
		cout << 1;
	}else cout << 0;
	return 0;
} 
