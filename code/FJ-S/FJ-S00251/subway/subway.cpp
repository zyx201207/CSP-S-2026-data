#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010, M = 510, INF = 1e18;
int c, m, n, d, q;
int w[N], k[M], dis[M][M], dik[M][M];
bool vis[M];
vector<pair<int, int> > vec[M], poi[N];
int num;
int head[M], to[N << 1], nxt[N << 1], wk[N << 1];
void add(int u, int v, int val) {
	to[++num] = v, nxt[num] = head[u];
	wk[num] = val, head[u] = num;
}
// 路线号到另外一些路线号的路程 
void bfs(int p) {
	queue<pair<int, int> > q;
	for (int i = 0; i < k[p]; i++) 
		q.push({vec[p][i].first, vec[p][i].second});
	while (!q.empty()) {
		int u = q.front().first, w = q.front().second;
		q.pop();
		int l = poi[u].size();
		for (int i = 0; i < l; i++) {
			int v = poi[u][i].first;
			dis[p][v] = min(dis[p][v], poi[u][i].second + w);
			dis[v][p] = min(dis[v][p], poi[u][i].second + w);
		}
	}
}
void dij(int p) {
	priority_queue<pair<int, int> > q;
	q.push({0, p});
	for (int i = 1; i <= n; i++) vis[i] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i], val = wk[i];
			if (dik[p][u] + val < dik[p][v]) {
				dik[p][v] = dik[p][u] + val;
				q.push({-dik[p][v], v});
			}
		}
	}
}
void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			dis[i][j] = INF, dik[i][j] = INF;
	for (int i = 1; i <= n; i++) 
		dis[i][i] = 0, dik[i][i] = 0;
	for (int i = 1; i <= n; i++) bfs(i);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			if (dis[i][j] != INF) 
				add(i, j, dis[i][j]);
	for (int i = 1; i <= n; i++) dij(i); 
}
int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar(); 
	}
	return x;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		k[i] = read();
		for (int j = 1; j <= k[i]; j++) {
			int a, t; a = read(), t = read();
			vec[i].push_back({a, t});
			poi[a].push_back({i, t});
		}
	}
	init();
	while (q--) {
		int x, y; x = read(), y = read();
		int ans = INF;
		int lx = poi[x].size();
		int ly = poi[y].size();
		for (int i = 0; i < lx; i++) {
			for (int j = 0; j < ly; j++) {
				int ux = poi[x][i].first;
				int wx = poi[x][i].second;
				int uy = poi[y][j].first;
				int wy = poi[y][j].second;
				int d = dik[ux][uy];
				int s = wx + wy + d + w[x] + w[y];
				ans = min(ans, s);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
