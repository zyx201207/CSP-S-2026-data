//GZ-J00144  张心恬  贵阳市白云区华师一学校 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
string c1, c2, s1, s2;
string t1, t2, str = "ABCZDF";
int a, b, c, d;
bool check(char x, char y){ 
	int tmp1 = 0, tmp2 = 0;
	if (x == 'A' || x == 'B' || x =='C') tmp1 = 1;
	else tmp1 = 2;
	if (y == 'A' || y == 'B' || y =='C') tmp2 = 1;
	else tmp2 = 2;
	return (tmp1 == tmp2);
}
bool check2(char x, char y){
	int d1 = str.find(x);
	int d2 = str.find(y);
	if (abs(d1 - d2) == 1) return 1;
	return 0;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	t1 = s1[0] + s1[1];
	t2 = s2[0] + s2[1];
	if (c1 == c2) a = 1;
	if (a && t1 == t2) b = 1;
	if (a && b && check(s1[2], s2[2])) c = 1;
	if (a && b && c && check2(s1[2], s2[2])) d = 1;
	cout << a << b << c << d; 
	return 0;
} 
