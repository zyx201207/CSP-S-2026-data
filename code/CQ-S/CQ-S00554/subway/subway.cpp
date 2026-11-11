#include <bits/stdc++.h>

using namespace std;
const int N = 5e5;
int c, n, m, d, q;
long long dp[505][505], v[N + 5];
vector<long long> g[N + 5], p[N + 5];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dp, 0x3f, sizeof dp);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> v[i];
	}
	for(int i = 1; i <= m; i ++) {
		dp[i][i] = 0;
		int k, x, y;
		cin >> k;
		for(int j = 1; j <= k; j ++) {
			cin >> x >> y;
			p[x].emplace_back(i);
			g[x].emplace_back(y);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int l = 0; l < p[i].size(); l ++) {
			for(int r = 0; r < p[i].size(); r ++) {
				dp[p[i][l]][p[i][r]] = min(dp[p[i][l]][p[i][r]], g[i][l] + g[i][r]);
			}
		}
	}
	for(int k = 1; k <= m; k ++) {
		for(int i = 1; i <= m; i ++) {
			for(int j = 1; j <= m; j ++) {
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}
	while(q --) {
		int x, y;
		long long ans = dp[0][0];
		cin >> x >> y;
		for(int l = 0; l < p[x].size(); l ++) {
			for(int r = 0; r < p[y].size(); r ++) {
				ans = min(ans, dp[p[x][l]][p[y][r]] + g[x][l] + g[y][r]);
			}
		}
		cout << ans + v[x] + v[y] << '\n';
	}
	return 0;
}

