#include <bits/stdc++.h>
#define int long long
using namespace std;

bool ST;

const int N = 1e6 + 5;
int id, n, m, d, q;
long long w[N];

int tot;
struct Edge1 {
	int u, v; long long w;
	bool operator < (const Edge1 &T) const { return w < T.w; } 
} e1[N];

struct Edge { int v, nxt; long long w; } e[N << 1];
int ecnt, head[N];
void addEdge (int u, int v, long long w) {
	e[++ecnt] = {v, head[u], w};
	head[u] = ecnt;
}

int fad[N];
int find (int x) { return fad[x] == x ? x : fad[x] = find (fad[x]); }

long long val[N];
int dep[N], fa[N][25];
void dfs (int u, int fath) {
	dep[u] = dep[fath] + 1;
	fa[u][0] = fath;
	for (int i = 1; i <= 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fath) continue;
		val[v] = val[u] + e[i].w;
		dfs (v, u);
	}
}

int lca (int x, int y) {
	if (dep[x] < dep[y]) swap (x, y);
	for (int i = 20; i >= 0; --i) if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; --i) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

bool ED;

signed main () {

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);

	cin >> id >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= m << 1; ++i) fad[i] = i;
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t; cin >> a >> t;
			e1[++tot] = (Edge1) {m + i, a, t};
		}
	}
	
	sort (e1 + 1, e1 + tot + 1);
	for (int i = 1; i <= tot; ++i) {
		int u = e1[i].u, v = e1[i].v, w = e1[i].w;
		int fu = find (u), fv = find (v);
		if (fu == fv) continue;
		fad[fu] = fv;
		addEdge (u, v, w);
		addEdge (v, u, w);
	}
	
	dfs (1, 0);
	while (q--) {
		int x, y;
		cin >> x >> y;
		int l = lca (x, y);
		cout << val[x] + val[y] - 2LL * val[l] + w[x] + w[y] << '\n';
	}
	
	return 0;
}

