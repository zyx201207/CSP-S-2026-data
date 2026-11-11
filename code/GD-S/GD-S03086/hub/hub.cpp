#include <cstdio>
#include <cstring>

inline void swap(int &x, int &y) { int temp = x; x = y, y = temp; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

const int N = 2e6 + 1;

int ipt, tests;
int n, k, ans;
int head[N], to[N << 1], nxt[N << 1], tot;
int siz[N], fa[N], son[N], dep[N], top[N];
int sel[N];
bool vis[N], vis1[N];

inline void add_edge(int u, int v) { nxt[++tot] = head[u], to[tot] = v, head[u] = tot; }

void dfs1(int u, int p) {
	siz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
	for (int e = head[u], v; e; e = nxt[e]) {
		v = to[e]; if (v == p) continue;
		dfs1(v, u); siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t; if (son[u]) dfs2(son[u], t);
	for (int e = head[u], v; e; e = nxt[e]) {
		v = to[e]; if (v == fa[u]) continue;
		dfs2(v, v);
	}
}

inline int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	} return dep[x] < dep[y] ? x : y;
}

void color(int u) {
	vis1[u] = 1;
	for (int e = head[u], v; e; e = nxt[e]) {
		v = to[e]; if (v == fa[u] || !vis[v] || vis1[v]) continue;
		color(v);
	}
}

void check() {
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i++) vis1[i] = 0;
	for (int i = 1; i <= k; i++) if (!vis1[sel[i]]) { color(sel[i]); cnt++; }
	if (cnt > 2) return;
	for (int i = 1; i <= n; i++) {
		int mi = 1e9;
		for (int j = 1; j <= k; j++) {
			mi = min(mi, dep[i] + dep[sel[j]] - 2 * dep[lca(i, sel[j])]);
		}
		res = max(res, mi);
	}
	ans = min(ans, res);
}

void dfs3(int i, int lst, int len) {
	if (len == k) { check(); return; }
	if (i == n + 1) return;
	sel[len + 1] = i, vis[i] = 1; dfs3(i + 1, 1, len + 1); vis[i] = 0;
	dfs3(i + 1, 0, len);
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1
2
*/

int main() {
	std::freopen("hub.in", "r", stdin);
	std::freopen("hub.out", "w", stdout);
	scanf("%d %d", &ipt, &tests);
	while (tests--) {
		memset(head, 0, sizeof head);
		memset(vis, 0, sizeof vis);
		memset(vis1, 0, sizeof vis1);
		memset(son, 0, sizeof son); tot = 0, ans = 1e9;
		scanf("%d %d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v);
			add_edge(u, v); add_edge(v, u);
		} dfs1(1, 0); dfs2(1, 1); dfs3(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}

