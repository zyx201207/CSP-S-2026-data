#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long

const int N = 505, M = 500050;

int C, n, m, d, q, w[M];
ll dist[N][N];

vector<pair<int, int>> zhan[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int xx, yy;
			scanf("%d%d", &xx, &yy);
			zhan[xx].pb({i, yy});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto j : zhan[i]) {
			for (auto k : zhan[i]) if (j != k) {
				dist[j.fi][k.fi] = dist[k.fi][j.fi] = min(dist[j.fi][k.fi], (ll)j.se + k.se);
			} 
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--) {
		int xr, yr;
		scanf("%d%d", &xr, &yr);
		ll ans = 1e18;
		for (auto i : zhan[xr]) 
			for (auto j : zhan[yr]) {
				ans = min(ans, dist[i.fi][j.fi] + i.se + j.se);
			}
		ans += w[xr] + w[yr];
		printf("%lld\n", ans);
	}
	return 0;
}
