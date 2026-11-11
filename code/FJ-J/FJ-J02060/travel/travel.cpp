#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0

using namespace std;
typedef long long ll;
typedef string str;

str c1, s1, c2, s2;

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
				cout << "1";
				if (s1[2] <= 'C' && s2[2] <= 'C') {
					if ((int)abs(s1[2] - s2[2]) == 1) {
						cout << "1" << el;
					} else {
						cout << "0" << el;
					}
				} else {
					cout << "1" << el;
				}
			} else {
				cout << "00" << el;
			}
		} else {
			cout << "000" << el;
		}
	} else {
		cout << "0000" << el;
	}
	r0;
}
