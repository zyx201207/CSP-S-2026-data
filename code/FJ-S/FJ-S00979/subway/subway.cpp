#include <bits/stdc++.h>
#define u first
#define w second
using namespace std;
const int N = 510, M = 500010;
long long c, n, d, q, m, G[N][N], w[M], x, y, cnt[M];
pair<int, long long> g[M][30];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1, k; i <= n; i ++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j ++) {
			cin >> a >> t;
			g[a][++ cnt[a]] = make_pair(i, t);
		}
	}
	memset(G, 0x3f, sizeof G);
	for (int i = 1; i <= n; i ++)
		G[i][i] = 0;
	for (int i = 1; i <= m; i ++)
		for (int j = 1; j <= cnt[i]; j ++)
			for (int k = 1; k < j; k ++) {
				auto t1 = g[i][j], t2 = g[i][k];
				G[t1.u][t2.u] = min(G[t1.u][t2.u], t1.w + t2.w);
				G[t2.u][t1.u] = min(G[t2.u][t1.u], t1.w + t2.w);
			}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	while (q --) {
		cin >> x >> y;
		long long ans = LLONG_MAX;
		for (int j = 1; j <= cnt[x]; j ++)
			for (int k = 1; k <= cnt[y]; k ++) {
				ans = min(ans, G[g[x][j].u][g[y][k].u] + g[x][j].w + g[y][k].w);
//				cout << q << " " << G[g[x][j].u][g[y][k].u] << "\n";
			}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
/*
0 3 7 20 5
1 2 3 4 5 6 7
3 1 1 2 2 3 3
4 2 4 3 5 4 6 5 7
4 4 8 5 9 6 10 7 11
1 7
2 6
3 4
2 5
1 4
*/
