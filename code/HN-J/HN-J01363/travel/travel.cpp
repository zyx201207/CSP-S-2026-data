#include <bits/stdc++.h>
#define int long long

using namespace std;

int a, b;
string c, d;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> c >> b >> d;
	if (a != b) {
		cout << "0000\n";
	} else {
		cout << 1;
		if (c[0] == d[0] && c[1] == d[1]) {
			cout << 1;
			if ((c[2] <= 'C' && d[2] <= 'C') || (c[2] > 'C' && d[2] > 'C')) {
				cout << 1;
				cout << (c[2] > 'C' || abs(c[2] - d[2]) == 1) << '\n';
			} else {
				cout << "00\n";
			}
		} else {
			cout << "000\n";
		}
	}
  return 0;
}
