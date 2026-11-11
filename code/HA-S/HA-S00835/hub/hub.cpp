#include <bits/stdc++.h>
using namespace std;

/*
二分答案，然后变成什么呢？

选 k 个关键点，使它们至多在两个连通块，满足其他点到关键点的距离都 <= mid 
*/

const int N = 114;
int c, t, n, k, u, v, col[N];
vector<int> g[N];
bool vis[N];

void dfs(int u)
{
	vis[u] = 1;
	for(auto v : g[u]) if(col[v] && !vis[v]) dfs(v); 
}

int mn = 1e9;

void dfs2(int u, int d)
{
	vis[u] = 1;
	if(col[u]) { mn = min(mn, d); return;}
	for(auto v : g[u])
		if(!vis[v]) dfs2(v, d + 1);
	return;
}

void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i < n; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 1e9;
	for(int s = 0; s < (1 << n); s++)
	{
		if(__builtin_popcount(s) != k) continue;
		for(int i = 1; i <= n; i++)
			col[i] = (s >> (i - 1)) & 1, vis[i] = 0;
		int idx = 0;
		for(int i = 1; i <= n; i++)
			if(col[i] && !vis[i]) dfs(i), idx++;
		if(idx > 2) continue;
		int mx = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!col[i])
			{
				for(int j = 1; j <= n; j++) vis[j] = 0;
				mn = 1e9, dfs2(i, 0);
//				co
				mx = max(mx, mn);
			}
		}
//		if(mx == 0) cout << s << ' ';
		ans = min(ans, mx);
	}
	cout << ans << '\n';
	return;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

