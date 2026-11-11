#include <bits/stdc++.h>
using namespace std;
int a, b;
string x, y;
int seat1, seat2;
char c1, c2;
void seperate() {
	seat1 = (x[0] - '0') * 10 + (x[1] - '0');
	c1 = x[2];
	seat2 = (y[0] - '0') * 10 + (y[1] - '0');
	c2 = y[2];
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> x >> b >> y;
	seperate();
	bool flag = (a == b);
	cout << flag;
//	cout << seat1 << ' ' << c1 << ' ' << seat2 << ' ' << c2;
	flag = flag && (seat1 == seat2);
	cout << flag;
	flag = flag && (('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C') || ('E' <= c1 && c1 <= 'F' && 'E' <= c2 && 'f' <= c2)); 
	cout << flag;
	flag = flag && (abs(c1 - c2) == 1);
	cout << flag;
	return 0;
}
