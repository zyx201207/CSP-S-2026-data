#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
typedef pair<int, int> PII;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 501010;
int C, n, m, dd, q, cnt;
int w[N], idx, len[N], g[550][550];
PII W[N][21];
vector<int> p[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	C = read(), m = read(), n = read(), dd = read(), q = read();
	for (int i = 1; i <= n; i ++) w[i] = read();
	for (int i = 1; i <= m; i ++) {
		int k = read();
		while (k --) {
			int a = read(), t = read();
			W[a][++ len[a]] = {t, i}; 
		}
	}
	for (int i = 1; i <= m; i ++)
		for (int j = 1; j <= m; j ++) g[i][j] = 1e18;
	for (int i = 1; i <= n; i ++)
		for (int u = 1; u <= len[i]; u ++)
			for (int v = 1; v <= len[i]; v ++) if (u != v) {
				int x = W[i][u].second, y = W[i][v].second;
				g[x][y] = min(g[x][y], W[i][u].first + W[i][v].first);
				g[y][x] = g[x][y];
			}
	for (int i = 1; i <= m; i ++) g[i][i] = 0;
	for (int k = 1; k <= m; k ++)
		for (int i = 1; i <= m; i ++)
			for (int j = 1; j <= m; j ++) 
				if (g[i][k] != 1e18 && g[k][j] != 1e18 && i != j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while (q --) {
		int u = read(), v = read();
		int ans = 1e18;
		for (int i = 1; i <= len[u]; i ++) 
			for (int j = 1; j <= len[v]; j ++) 
				ans = min(ans, W[u][i].first + W[v][j].first + g[W[u][i].second][W[v][j].second]); 
		printf("%lld\n", ans + w[u] + w[v]);
	}
	return 0;
}
