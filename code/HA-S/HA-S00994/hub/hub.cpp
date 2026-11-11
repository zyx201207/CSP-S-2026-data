#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, K = 31;

vector<int> g[N];
bool ok[N];
int c, T, n, k, fath[N][K], pa[N], dep[N], ans = 2e9;

void dfs (int u, int fr)
{
	fath[u][0] = fr, dep[u] = dep[fr] + 1;
	for (int i = 1; i < K; i++) fath[u][i] = fath[fath[u][i - 1]][i - 1];
	for (auto to : g[u]) if (to != fr) dfs (to, u);
	return ;
}

static inline int lca (int u, int v)
{
	if (dep[u] <= dep[v]) swap (u, v);
	for (int k = K - 1; k >= 0; k--) if (dep[fath[u][k]] >= dep[v]) u = fath[u][k];
	if (u == v) return u;
	for (int k = K - 1; k >= 0; k--) if (fath[u][k] != fath[v][k]) u = fath[u][k], v = fath[v][k];
	return fath[u][0]; 
}

int findi (int u) {
	if (u == pa[u]) return u;
	else return pa[u] = findi (pa[u]);
}

static inline void merge (int u, int v) {
	int fu = findi (u), fv = findi (v);
	if (fu != fv) pa[fu] = fv;
	return ;
}

bool check ()
{
	for (int i = 1; i <= n; i++) pa[i] = i;
	for (int i = 1; i <= n; i++) {
		if (ok[i]) for (auto to : g[i]) if (ok[to]) merge (to, i);
 	}
 	
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (ok[i] && pa[i] == i) cnt++;
	return (cnt == 2);
}

static inline int dis (int u, int v) {
	int lcp = lca (u, v);
	return (dep[u] + dep[v] - dep[lcp] * 2);
}

void calc (int cur, int cnt)
{
	if (cnt > k) return ;
	if (cnt + (n - cur + 1) < k) return ;
	
	if (cur == n + 1) 
	{
		if (cnt != k || !check ()) return ; 
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (ok[i]) continue;
			int k = 2e9;
			for (int j = 1; j <= n; j++) {
				if (!ok[j]) continue;
				k = min (k, dis (i, j));
			}
			sum = max (sum, k);
		}
		ans = min (ans, sum);
		return ;
	} else 
	{
		ok[cur] = true;
		calc (cur + 1, cnt + 1);
		ok[cur] = false; 
		calc (cur + 1, cnt);
	}
	return ;
}

void solve ()
{
	cin >> n >> k, ans = 2e9;
	for (int i = 1; i <= n; i++) g[i].clear ();
	for (int i = 1, u, v; i + 1 <= n; i++) {
		cin >> u >> v;
		g[u].emplace_back (v), g[v].emplace_back (u);
	}	
	dfs (1, 0);
	calc (1, 0);
	cout << ans << "\n";
	return ;
}

signed main ()
{
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> c >> T;
	while (T--) solve ();	
	
	return 0;
}