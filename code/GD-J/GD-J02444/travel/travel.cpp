#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string c1, c2, s1, s2;

int f(string s) {
	int ret = (s[0] - '0') * 10 + (s[1] - '0');
	return ret;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = f(c1), b = f(c2), c = f(s1), d = f(s2);
	bool t1 = (a == b);
	cout << t1;
	bool t2 = (t1 and c == d);
	cout << t2;
	bool t3 = (t2 and (s1[2] <= 'C' and s2[2] <= 'C') or (s1[2] >= 'D' and s2[2] >= 'D'));
	cout << t3;
	cout << (t3 and abs(s1[2] - s2[2]) == 1);
	return 0;
} 
