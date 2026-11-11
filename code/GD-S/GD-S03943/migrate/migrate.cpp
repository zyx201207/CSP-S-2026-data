#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans;
}
const int N = 2e6 + 7, M = 5e3 + 7, inf = 1e9 + 7;
int a[N], dp[M][M];
int f[M][M];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%lld%lld", &c, &T);
	while (T--) {
		int n, m, ans = 0;
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		if (c == 11 || c == 12)  {
			int d = m / (a[2] - a[1]);
			if (d <= 1 || 2 * d - 1 >= n) cout << "0\n";
			else cout << n - 2 * d + 1 << endl;	
		} 
		else {
			for (int d = 0; d < n; ++d) {
				for (int i = 1; i + d <= n; ++i) {
					int j = i + d;
					f[i][j] = inf, dp[i][j] = 0;
					if (a[j] - a[i] <= m) {
						dp[i][j] = 1, f[i][j] = 1;
						continue;
					}
					for (int k = i + 1; k < j; ++k) {
						if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j], dp[i][j] = 0;
						if (f[i][k] + f[k][j] == f[i][j]) dp[i][j] += dp[i][k] * dp[k][j];
					}
					if (dp[i][j] == 2) ++ans;
				}
			}
			cout << ans << endl;
		}
	} 
	return 0;
} 
