#include <bits/stdc++.h>
using namespace std;
int getseat(string s) {
	return (s[2] - 'A');
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	bool fg = true;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (fg = fg && (c1 == c2));
	cout << (fg = fg && (s1.substr(0, 2) == s2.substr(0, 2)));
	cout << (fg = fg && ((getseat(s1) < 3) == (getseat(s2) < 3)));
	cout << (fg = fg && (abs(getseat(s1) - getseat(s2)) == 1));
	cout << endl;
}
