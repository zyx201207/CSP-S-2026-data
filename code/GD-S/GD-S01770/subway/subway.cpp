#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
const ll inf = 1e18;
int tc, n, m, d, q, son[N][25], tot[N];
ll dis[510][510], t[N][25], w[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &tc, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			son[x][++tot[x]] = i;
			t[x][tot[x]] = y;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= tot[i]; j++) {
			for (int k = j + 1; k <= tot[i]; k++) {
				dis[son[i][j]][son[i][k]] = min(dis[son[i][j]][son[i][k]], t[i][j] + t[i][k]);
				dis[son[i][k]][son[i][j]] = min(dis[son[i][j]][son[i][k]], t[i][j] + t[i][k]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = w[x] + w[y];
		ll res = inf;
		for (int i = 1; i <= tot[x]; i++) {
			for (int j = 1; j <= tot[y]; j++) {
				res = min(res, t[x][i] + t[y][j] + dis[son[x][i]][son[y][j]]);
			}
		}
		printf("%lld\n", ans + res);
	}
	return 0;
}
