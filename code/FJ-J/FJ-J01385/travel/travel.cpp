#include <iostream>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)

int n, m;
int x, y;
int u, v;
string s, t;

int main() {
	Write by ___NightDay___;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> s >> m >> t;
	x = (s[0] - '0') * 10 + (s[1] - 0);
	y = (t[0] - '0') * 10 + (t[1] - 0);
	u = s[2] - 'A' + 1;
	if (u == 6) {
		u = 5;
	}
	v = t[2] - 'A' + 1;
	if (v == 6) {
		v = 5;
	}
	if (n == m) {
		cout << "1";
		if (x == y) {
			cout << "1";
			if ((u <= 3 && v <= 3) || (u >= 4 && v >= 4)) {
				cout << "1";
				if ((u - v == 1) || (v - u == 1)) {
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
// 100pts
