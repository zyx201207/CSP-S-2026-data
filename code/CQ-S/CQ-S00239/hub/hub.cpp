#include <bits/stdc++.h>
using namespace std;

bool ST;

const int N = 2e6 + 5;
int id, t;
int n, k, mu[N], mv[N];
struct Edge { int v, nxt; } e[N << 1];
int ecnt, head[N];
void addEdge (int u, int v) { 
	e[++ecnt] = {v, head[u]};
	head[u] = ecnt;
}

int dep[N], fa[N][25];
void dfs1 (int u, int fath) {
	dep[u] = dep[fath] + 1;
	fa[u][0] = fath;
	for (int i = 1; i <= 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fath) continue;
		dfs1 (v, u);
	}
}

int lca (int x, int y) {
	if (dep[x] < dep[y]) swap (x, y);
	for (int i = 20; i >= 0; --i) if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; --i) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

bool vis[N];
int a[N], ans = 0x3f3f3f3f;
void dfs (int depp) {
	if (depp == k + 1) {
		int tmp = 0, cnt = 0;
		for (int i = 1; i < n; ++i) if (vis[mu[i]] && vis[mv[i]]) cnt++;
		if (k - cnt > 2) return ;
		for (int i = 1; i <= n; ++i) {
			if (vis[i]) continue;
			int ret = 0x3f3f3f3f;
			for (int j = 1; j <= k; ++j) {
				int l = lca (i, a[j]), dis = dep[i] + dep[a[j]] - 2 * dep[l];
				ret = min (ret, dis);
			}
			tmp = max (tmp, ret);
		}
		ans = min (ans, tmp);
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			a[depp] = i;
			dfs (depp + 1);
			vis[i] = false;
		}
	}
}

void solve () {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
		mu[i] = u, mv[i] = v;
	}
	dfs1 (1, 0);
	dfs (1);
	cout << ans << '\n';
}

void clear () {
	ecnt = 0;
	memset (head, 0, sizeof head);
	memset (e, 0, sizeof e);
	memset (dep, 0, sizeof dep);
	memset (fa, 0, sizeof fa);
	ans = 0x3f3f3f3f;
}

bool ED;

int main () {
	
	cerr << "[Memory] " << (&ST - &ED) / 1024 / 1024 << " MB\n";

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);

	cin >> id >> t;
	while (t--) {
		solve ();
		clear ();
	}
	
	return 0;
}


