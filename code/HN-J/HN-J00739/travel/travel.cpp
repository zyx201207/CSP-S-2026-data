#include <bits/stdc++.h>
using namespace std;

bool side(char c1, char c2, bool f) {
	if (c1 == 'D' && c2 == 'F') {
		return 1;
	}
	if (c1 == 'A') {
		if (c2 == 'B' || c2 == 'C') return 1;
	}
	if (c1 == 'B') {
		if (c2 == 'A' || c2 == 'C') return 1;
	}
	if (c1 == 'C') {
		if (c2 == 'A' || c2 == 'B') return 1;
	}
	if (f) return 0;
	return side(c2, c1, 1);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s, t;
	int a, b;
	cin >> a >> s >> b >> t;
	if (a == b) {
		cout << '1';
		if (s.substr(0, 2) == t.substr(0, 2)) {
			cout << '1';
			if (side(s[2], t[2], 0)) {
				cout << '1';
				if (abs(s[2] - t[2]) == 1) {
					cout << '1';
				} else cout << '0';
			} else cout << "00";
		} else {
			cout << "000";
		}
	} else cout << "0000";
	return 0;
}

