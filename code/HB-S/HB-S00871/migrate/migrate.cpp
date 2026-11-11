#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6 + 5;
int c, q, n, a[MAXN], d;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> q;
	while (q--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n < d + 2) {
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for (int i = d + 2; i <= n; i++) {
			if (a[i] - a[i - d - 1] > d) {
				int cnt = 0;
				for (int j = i - d; j <= i - 1; j++) {
					if (a[j] - a[i - d - 1] <= d && a[i] - a[j] <= d)
						cnt++;
				}
				if (cnt == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
