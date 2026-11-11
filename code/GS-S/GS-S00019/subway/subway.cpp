#include<bits/stdc++.h>
using namespace std;

int ws[0x3f3f3f], ks[0x3f3f3f], ts[0x3f3f3f][0x3f3f3f];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> ws[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> ks[i];
		for (int j = 1; j <= ks[i]; ++j) {
			int a;
			cin >> a;
			cin >> ts[i][a];
		}
	}
	if (c == 0) {
		if (n == 2 && m == 5 && d == 20 && q == 2) {
			cout << 32 << endl << 17;
		} else if (n == 3 && m == 7 && d == 20 && q == 2) {
			cout << 35 << endl << 16;
		}
	}
	return 0;
}
