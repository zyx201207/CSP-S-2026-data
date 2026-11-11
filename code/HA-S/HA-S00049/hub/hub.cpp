#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;
const int INF = 1 << 30;

int c, test, n, m, ans, d[N];
vector<int> edges[N];
bool b[N], vis[N];

void dfs1(int u) {
	vis[u] = true;
	for (auto v : edges[u]) if (b[v] && !vis[v])
		dfs1(v);
}

void dfs2(int u, int fa, int dep) {
	d[u] = min(d[u], dep);
	for (auto v : edges[u]) if (v != fa) 
		dfs2(v, u, dep + 1);
}

void dfs(int x, int y) {
	if (y > m) return;
	if (n - x + 1 < m - y) return;
	if (x == n + 1) {
		if (y != m) return;
		int tot = 0;
		for (int i = 1; i <= n; i++) 
			vis[i] = false, d[i] = 1 << 30;
		for (int i = 1; i <= n; i++)
			if (b[i] && !vis[i]) {
				dfs1(i);
				tot++;
			}
		if (tot > 2) return;
//		for (int i = 1; i <= n; i++)
//			printf("%d", b[i]);
//		printf("\n");
		for (int i = 1; i <= n; i++)
			if (b[i])
				dfs2(i, 0, 0);
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = max(res, d[i]);
		ans = min(ans, res);
		return;
	}
	b[x] = false;
	dfs(x + 1, y);
	b[x] = true;
	dfs(x + 1, y + 1);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) edges[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	ans = INF;
	dfs(1, 0);
	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &test);
	for (; test--; )
		solve();
	return 0;
}

