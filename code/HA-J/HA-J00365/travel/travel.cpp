#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool b1 = 0, b2 = 0, b3 = 0;
	if (c1 == c2) {
		cout << 1;
		b1 = 1;
	}
	else cout << 0;
	if (b1 && s1.substr(0, 2) == s2.substr(0, 2)) {
		cout << 1;
		b2 = 1;
	}
	else cout << 0;
	if (b2 && ((s1[2] < 'D' && s2[2] < 'D') || (s1[2] > 'C' && s2[2] > 'C'))) {
		cout << 1;
		b3 = 1;
	}
	else cout << 0;
	if (b3 && (char(s1[2] + 1) == s2[2] || char(s2[2] + 1) == s1[2]) && (s1[2] != 'C' && s2[2] != 'D') && (s2[2] != 'C' && s1[2] != 'D')) cout << 1;
	else cout << 0;
	return 0;
}
//I love luogu!
//I love luogu!
//I love luogu!
//I love kkksc24!
//I love kkksc24!
//I love kkksc24!
//I love chen_zhe!
//I love chen_zhe!
//I love chen_zhe!
//I love 一扶苏一!
//I love 一扶苏一!
//I love 一扶苏一!
