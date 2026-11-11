#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e3 + 10;
int c, T, n, d, maxr, a[N], dp[N][N], sum[N][N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				sum[i][j] = 0;
				if (i == j) dp[i][j] = 0;
				else if (abs(a[i] - a[j]) <= d) dp[i][j] = sum[i][j] = 1;
				else dp[i][j] = INT_MAX;
			}
		}
		
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (dp[i][j] > dp[i][k] + dp[k][j] + 1) {
						dp[i][j] = dp[i][k] + dp[k][j] + 1;
						sum[i][j] = 1;
					} else if (dp[i][j] < INT_MAX && dp[i][j] == dp[i][k] + dp[k][j] + 1) {
						sum[i][j] += 1;
					}
				}
			}
		}
		
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (sum[i][j] == 2) {
					ans++;
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
