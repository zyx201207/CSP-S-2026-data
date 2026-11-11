#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d;
	char e, f;
	cin >> a >> c >> e >> b >> d >> f;
//	cout << a << b << c << d;
	int m = int(e);
	int n = int(f);
//	cout << m << " " << n;
	if (a == b) {
		cout << "1";
		if (c == d) {
			cout << "1";
			if (m >= 65 && m <= 67 && n >= 65 && n <= 67) {
				cout << "1";
				if (m - n == 1 || m - n == -1) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else if (m >= 68 && m <= 69 && n >= 68 && n <= 69) {
				cout << "11";
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
