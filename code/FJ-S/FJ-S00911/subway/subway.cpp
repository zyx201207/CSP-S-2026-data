#include <bits/stdc++.h>
#define int long long
#define pii std :: pair <int, int>
#define fi first
#define se second

constexpr int N = 5e5 + 5, INF = 1e18;

int dp[505][505], w[N];
int c, n, m, d, q;
std :: vector <pii> G[N];

void solve () {
	std :: cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) std :: cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp[i][j] = (i == j ? 0 : INF);
		}
	}
	for (int i = 1; i <= n; i ++) {
		int k;
		std :: cin >> k;
		for (int j = 1; j <= k; j ++) {
			int x, w;
			std :: cin >> x >> w; G[x].push_back ({i, w});
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (pii v : G[i]) {
			for (pii h : G[i]) {
				if (v.fi == h.fi) {
					continue;
				}
				dp[v.fi][h.fi] = std :: min (dp[v.fi][h.fi], v.se + h.se);
				dp[h.fi][v.fi] = std :: min (dp[h.fi][v.fi], v.se + h.se);
			}
		}
	}
	for (int k = 1; k <= n; k ++) {
		for (int s = 1; s <= n; s ++) {
			for (int t = 1; t <= n; t ++) {
				dp[s][t] = std :: min (dp[s][t], dp[s][k] + dp[k][t]);
			}
		}
	}
	while (q --) {
		int x, y;
		std :: cin >> x >> y;
		int ans = INF;
		for (pii v : G[x]) {
			for (pii h : G[y]) {
				ans = std :: min (ans, v.se + dp[v.fi][h.fi] + h.se);
			}
		}
		ans += w[x] + w[y];
		std :: cout << ans << '\n';
	}
}

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
//	int TTT; std :: cin >> TTT; while (TTT --)
	solve ();

	return 0;
}

