#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

constexpr int N = 505, M = 5e5 + 5;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;

int cid, n, m, d, q;

int w[M];

struct edge {
	int to, nxt, w;
} e[M << 1];
int head[M + N], ecnt;
void add(int x, int y, int w) {
//	debug("%d -> %d (%d)\n", x, y, w);
	e[++ecnt] = {y, head[x], w}, head[x] = ecnt;
}

long long dis[M + N];
bool vis[M + N];

long long spfa(int s, int t) {
	queue<int> q;
	for (int i = 1; i <= m + n; i++) dis[i] = INF;
	q.emplace(s);
	vis[s] = 1;
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				if (!vis[v])
					vis[v] = 1, q.emplace(v);
			}
		}
	}
	return dis[t];
}

//long long a[N];
//int dep[N];
//int son[N], fa[N], siz[N], top[N];
//
//void dfs1(int u, int fat) {
////	debug("visiting %d\n", u);
//	fa[u] = fat;
//	siz[u] = 1;
//	dep[u] = dep[fat] + 1;
//	for (int i = head[u]; i; i = e[i].nxt) {
//		int v = e[i].to;
//		if (v == fat) continue;
//		a[v] = a[u] + e[i].w;
//		dfs1(v, u);
//		siz[u] += siz[v];
//		if (siz[v] > siz[son[u]])
//			son[u] = v;
//	}
//}
//void dfs2(int u, int tp) {
//	top[u] = tp;
//	if (son[u]) dfs2(son[u], tp);
//	for (int i = head[u]; i; i = e[i].nxt) {
//		int v = e[i].to;
//		if (!top[v])
//			dfs2(v, v);
//	}
//}
//
//int lca(int x, int y) {
//	while (top[x] != top[y]) {
//		if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
//		else y = fa[top[y]];
//	}
//	return dep[x] < dep[y] ? x : y;
//}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> cid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];

	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
//		debug("line %d\n", i);
		while (k--) {
			int a, t; cin >> a >> t;
			add(m + i, a, t);
			add(a, m + i, t);
		}
	}
	
//	debug("node cnt = %d ecnt = %d\n", m + n, ecnt / 2);
	
//	dfs1(1, 0);
//	dfs2(1, 1);
	
	while (q--) {
		int x, y; cin >> x >> y;
		
		cout << spfa(x, y) + w[x] + w[y] << "\n";

//		int lc = lca(x, y);
////		debug("a[%d] = %d, a[%d] = %d\n", x, a[x], y, a[y]);
////		debug("lca(%d, %d) = %d, whose a = %d\n", x, y, lc, a[lc]);
//		long long ans = a[x] + a[y] - 2 * a[lc];
//		ans += w[x] + w[y];
//		cout << ans << "\n";
	}
	return 0;
}
