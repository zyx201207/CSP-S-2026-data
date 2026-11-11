#include <bits/stdc++.h>
#define int long long
#define N (int)(5e2 + 5)
#define M (int)(5e5 + 5)
#define INF (long long)1e18
using namespace std;
int c, n, m, d, q, w[M], g[N][N];
map <int, int> e[N];
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			e[i][a] = t;
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			g[i][j] = g[j][i] = INF;
			for (pair <int, int> k : e[i]) {
				if (e[j].count (k.first)) {
					g[i][j] = min (g[i][j], k.second + e[j][k.first]);
					g[j][i] = min (g[j][i], k.second + e[j][k.first]);
				}
			}
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (g[i][k] != INF && g[k][j] != INF)
					g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3 
*/
