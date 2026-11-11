#include <stdio.h>
#include <string.h>
#include <vector>
std::vector<int> g[1000005], sel;
int n, k, ans;
bool vis[1000005];
int fa[1000005][22], deep[1000005];
void pplca(int u, int f) {
	fa[u][0] = f;
	for (int i = 1; i < 22; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v: g[u]) {
		if (v == f) continue;
		deep[v] = deep[u] + 1;
		pplca(v, u);
	}
}
int lca(int x, int y) {
	if (deep[x] < deep[y]) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	for (int i = 21; i >= 0; i--) {
		if (deep[fa[x][i]] >= deep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 21; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
void con(int u, int f) {
	vis[u] = 0;
	for (int v: g[u]) {
		if (v == f) continue;
		if (vis[v]) con(v, u);
	}
}
void dfs(int u) {
	if (sel.size() == k) {
		int cnt = 0;
		for (int v: sel) vis[v] = 1;
		for (int v: sel) {
			if (vis[v]) {
				cnt++;
				if (cnt > 2) break;
				con(v, -1); 
			}
		}
		if (cnt <= 2) {
			int rad = 0;
			for (int i = 1; i <= n; i++) {
				int dist = 0x3f3f5f7f;
				for (int v: sel) {
					int lc = lca(i, v), dis = 0;
					if (lc == i || lc == v) {
						dis = deep[i] - deep[v];
						if (dis < 0) dis = -dis;
					} else {
						dis = deep[i] + deep[v] - (deep[lc] << 1);
					}
					if (dis < dist) dist = dis;
				}
				if (dist > rad) rad = dist;
			}
			if (rad < ans) ans = rad;
		}
		for (int v: sel) vis[v] = 0;
		return;
	}
	if (u > n) {
		return;
	}
	dfs(u + 1);
	sel.push_back(u);
	dfs(u + 1);
	sel.pop_back();
} 
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; scanf("%d %d", &c, &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		deep[1] = 0;
		ans = 0x3f3f5f7f;
		pplca(1, 1);
		dfs(1);
		for (int i = 1; i <= n; i++) g[i].clear();
		printf("%d\n", ans); 
	}
	return 0;
} 
