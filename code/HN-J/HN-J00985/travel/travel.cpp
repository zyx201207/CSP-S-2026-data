#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;
int ic1, ic2, is1, is2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	ic1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	ic2 = (c2[0] - '0') * 10 + (c2[1] - '0');
	is1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	is2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (ic1 == ic2) {
		cout << "1";
		if (is1 == is2) {
			cout << "1";
			if ((s1[2] < 'D' && s2[2] < 'D') || (s1[2] >= 'D' && s2[2] >= 'D')) {
				cout << "1";
				if (s1[2] + 1 == s2[2]) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
