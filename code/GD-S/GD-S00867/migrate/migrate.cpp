#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, g, k, ans, x[2000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		g = x[2] - x[1];
		k = d / g;
		for (int i = 1; i < n - k; i++) {
			ans += min(k - 1, n - i - k);
		}
		cout << ans << endl;
	}
	return 0;
}
