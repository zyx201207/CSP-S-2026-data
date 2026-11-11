#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int c, t, n, k, dis[5005][5005], f[500005];
vector<int> g[10005];
const int inf = 1 << 29;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				dis[i][j] = inf;
			}
		for (int i = 1; i <= n; i++)
			dis[i][i] = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v] = dis[v][u] = 1;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dis[i][k] + dis[k][j] < dis[i][j])
						dis[i][j] = dis[i][k] + dis[k][j];
		int kk = inf;
		for (int i = 1; i < (1 << (n - 1)); i++) {
			int c = 0;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1) {
					f[++c] = j + 1;
				}
			if (c != k)
				continue;
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				int res = inf;
				for (int l = 1; l <= c; l++) {
					res = min(res, dis[j][f[l]]);
				}
				ans = max(ans, res);
			}
			kk = min(kk, ans);
		}
		printf("%d\n", kk);
	}
	return 0;
}
