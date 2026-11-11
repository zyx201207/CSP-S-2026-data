#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
char h1, h2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	h1 = s1[2];
	h2 = s2[2];
	if (c1 == c2) {
		cout << 1;
		if (s1.substr(0, 2) == s2.substr(0, 2)) {
			cout << 1;
			if (h1 > h2) swap(h1, h2);
			if (h2 <= 'C') {
				if (h2 == 'B' && h1 == 'A') {
					cout << 11;
				} else if (h2 == 'C' && h1 == 'A') {
					cout << 10;
				} else if (h2 == 'C' && h1 == 'B') {
					cout << 11;
				}
			} else {
				if (h1 <= 'C') {
					cout << 0 << 0;
				} else if (h2 == 'F' && h1 == 'D') {
					cout << 11;
				}
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}