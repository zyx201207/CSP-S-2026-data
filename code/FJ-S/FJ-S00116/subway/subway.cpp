#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7, inf = 0x3f3f3f3f;

int w[N], a[505][1005], t[505][1005], ooo[1005][1005d];
int c, n, m, d, q;

priority_queue<pair<int, int>> qq;
int dis[1005], vis[1005], head[2005], nxt[2005], to[2005], oo[2005], cnt;

inline void add_edge(int u, int v, int ww) {
	nxt[++cnt] = head[u];
	to[cnt] = v;
	oo[cnt] = ww;
	head[u] = cnt;
}
inline void dijkstra(int s) {
	for (int i = 0; i < 1005; ++i)
		vis[i] = 0, dis[i] = inf;
	qq.push({0, s});
	dis[s] = 0;
	
	while (!qq.empty()) {
		int u = qq.top().second;
		qq.pop();
		 
		if (vis[u])
			continue;
			
		vis[u] = 1;
		
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			
			if (dis[v] > dis[u] + oo[i]) {
				dis[v] = dis[u] + oo[i];
				qq.push({-dis[v], v});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &w[i]);
	}
	
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		
		for (int j = 1; j <= k; ++j) 
			scanf("%d%d", &a[i][j], &t[i][j]);
		
		if (k == 2) {
			add_edge(a[i][1], a[i][2], t[i][2] + t[i][1]);
			add_edge(a[i][2], a[i][1], t[i][1] + t[i][2]);
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		dijkstra(i);
		for (int j = 1; j <= m; ++j)
			ooo[i][j] = dis[j];
}
	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = 0;
		ans += w[x] + w[y];
		ans += ooo[x][y];
		printf("%d\n", ans);
	}
	return 0;
}
