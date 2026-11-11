#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, cc, a, aa;
string s, ss;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> s >> cc >> ss;
	a = (s[0] - '0') * 10 + s[1] - '0';
	aa = (ss[0] - '0') * 10 + ss[1] - '0';
	if (c != cc) {
		cout << "0000";
	} else {
		cout << 1;
		if (a != aa) {
			cout << "000";
		} else {
			cout << 1;
			if ((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (ss[2] == 'A' || ss[2] == 'B' || ss[2] == 'C') || (s[2] == 'D' || s[2] == 'F') && (ss[2] == 'D' || ss[2] == 'F')) {
				cout << 1;
				if (abs(s[2] - ss[2]) == 1 && ((s[2] != 'C' && ss[2] != 'D') && (s[2] != 'D' && ss[2] != 'C'))) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		}
	}
	return 0;
}
