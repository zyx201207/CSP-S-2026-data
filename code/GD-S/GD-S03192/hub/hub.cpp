#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define vi vector<int>
#define i128 __int128
using namespace std;
const int maxn = 2e6 + 5, INF = 0x3f3f3f3f;
int c, t, n, k;
int f[maxn][30], dep[maxn];
vi g[maxn];
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i = 1; i <= 25; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(auto v: g[u])
	{
		if(v == fa) continue;
		dfs(v, u);
	}
}
int lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 25; ~i; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 25; ~i; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
int dis(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	int ans = 1e9;
	for(int s = 0; s < (1 << n); s++)
	{
		if(__builtin_popcount(s) != k) continue;
		vi city;
		int res = 0;
		for(int i = 1; i <= n; i++) if(s >> (i - 1) & 1) city.emplace_back(i);
		int cnt = 0;
		for(int i = 0; i < city.size(); i++)
		{
			int mn = 1e9;
			for(int j = 0; j < city.size(); j++) 
			{
				if(i == j) continue;
				mn = min(mn, dis(city[i], city[j]));
			}
			if(mn > 1) cnt++;
		}
		if(cnt > 2) continue;
		for(int i = 1; i <= n; i++)
		{
			int d = 1e9;
			for(auto v: city) d = min(d, dis(i, v));
			res = max(res, d);
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

