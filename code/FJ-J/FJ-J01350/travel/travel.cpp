#include <bits/stdc++.h>
using namespace std;

string c_1, s_1, c_2, s_2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	int cxhr, cxhx, phr, phx;
	char zwhr, zwhx;
	cxhr = (c_1[0] - '0') * 10 + (c_1[1] - '0');
	cxhx = (c_2[0] - '0') * 10 + (c_2[1] - '0');
	if (cxhr == cxhx) {
		cout << 1;
		phr = (s_1[0] - '0') * 10 + (s_1[1] - '0');
		phx = (s_2[0] - '0') * 10 + (s_2[1] - '0');
		if (phr == phx) {
			cout << 1;
			zwhr = s_1[2];
			zwhx = s_2[2];
			if (zwhr == 'A') {
				if (zwhx == 'B') cout << "11";
				if (zwhx == 'C') cout << "10";
				if (zwhx == 'D' || zwhx == 'F') cout << "00";
			} else if (zwhr == 'B') {
				if (zwhx == 'A' || zwhx == 'C') cout << "11";
				if (zwhx == 'D' || zwhx == 'F') cout << "00";
			} else if (zwhr == 'C') {
				if (zwhx == 'A') cout << "10";
				if (zwhx == 'B') cout << "11";
				if (zwhx == 'D' || zwhx == 'F') cout << "00";
			} else if (zwhr == 'D') {
				if (zwhx == 'F') cout << "11";
				if (zwhx == 'A' || zwhx == 'B' || zwhx == 'C') cout << "00";
			} else if (zwhr == 'F') {
				if (zwhx == 'D') cout << "11";
				if (zwhx == 'A' || zwhx == 'B' || zwhx == 'C') cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}

	return 0;
}
