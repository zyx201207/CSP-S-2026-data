#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int side(char c) {
	if (c >= 'A' && c <= 'C') return 0;
	return 1;
}

char right(char c) {
	if (c == 'D') return 'F';
	return c + 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool r1 = c1 == c2;
	bool r2 = r1 && (s1.substr(0, 2) == s2.substr(0, 2));
	bool r3 = r2 && (side(s1[2]) == side(s2[2]));
	bool r4 = r3 && (right(s1[2]) == s2[2] || right(s2[2]) == s1[2]);
	cout << r1 << r2 << r3 << r4;
	return 0;
}

