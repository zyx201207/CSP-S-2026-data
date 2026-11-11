#include <bits/stdc++.h>

using namespace std;

bool isLeft(char c) {
	return c == 'A' || c == 'B' || c == 'C';
}

bool isBeside(char a, char b) {
	if (a > b) swap(a, b);
	if (a == 'A' && b == 'B') return true;
	if (a == 'B' && b == 'C') return true;
	if (a == 'D' && b == 'F') return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a = false, b = false, c = false, d = false;
	if (c1 == c2) {
		a = true;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			b = true;
			if (! (isLeft(s1[2]) ^ isLeft(s2[2]))) {
				c = true;
				if (isBeside(s1[2], s2[2])) {
					d = true;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
