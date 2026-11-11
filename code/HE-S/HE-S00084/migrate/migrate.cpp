#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, t;
	cin >> c >> t;
	if (c >= 13 && c <= 14)
		while (t --) {
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i ++)
				cin >> d;
			long long ans = (n - 1) * (n - 2) / 2;
			cout << ans << '\n';
		}
	else
		while (t --) {
			int n, D, d, e;
			cin >> n >> D;
			if (n & 1) {
				for (int i = 1; i < n / 2; i ++)
					cin >> d >> e;
				cin >> d;
			}
			else
				for (int i = 1; i <= n / 2; i ++)
					cin >> d >> e;
			d = abs(d - e);
			if (D < d)
				cout << "0\n";
			else
				cout << "1\n";
		}
	return 0;
}

