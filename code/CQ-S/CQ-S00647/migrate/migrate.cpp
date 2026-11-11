#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e6 + 10;
long long x[N], dp[N], p[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int l = 1; l <= n; l++) {
			for (int i = 1; i <= n; i++) {
				p[i] = 1e18, dp[i] = 0;
			}
			dp[l] = 1, p[l] = 0;
			for (int r = l + 1; r <= n; r++) {
				//r 可以从任何满足 r <= x + d 的地方转移过来 
				long long s = x[r] - x[r - 1];
				for (int k = r - 1; k >= l; k--) {
					if (s <= d) {
						if (p[k] + 1 <= p[r]) {
							p[r] = p[k] + 1;
						}
					} else {
						break;
					}
					s += x[k] - x[k - 1];
				}
				s = x[r] - x[r - 1];
				for (int k = r - 1; k >= l; k--) {
					if (s <= d) {
						if (p[k] + 1 == p[r]) {
							dp[r] += dp[k];
						}
					} else {
						break;
					}
					s += x[k] - x[k - 1];
				}
				if (dp[r] == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	} 
	return 0;
}
