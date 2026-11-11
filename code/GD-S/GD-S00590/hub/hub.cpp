#include <bits/stdc++.h> 
#define int long long
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;

int c, n, k, cnt, col[N], dep[N], f[N][22];
vector<vector<int>> adj(N);

bool dfs_check(int x, int fa)
{
	if(col[x] == 1 && !col[fa])
	{
		cnt++;
		if(cnt > 2) return false;
	}
	for(int y : adj[x])
	{
		if(y == fa) continue;
		if(!dfs_check(y, x)) return false;
	}
	return true;
} 

void dfs(int x, int fa)
{
	f[x][0] = fa;
	for(int y : adj[x])
	{
		if(y == fa) continue;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
	return;
}

int lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	int c = dep[x] - dep[y];
	for(int i = 20; i >= 0; i--)
	{
		int d = (1 << i);
		if(d <= c)
		{
			x = f[x][i];
			c -= d;
		}
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; i--)
	{
		if(f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int calc(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

void solve()
{
	cin >> n >> k;
	for(int i = 0; i <= n; i++) adj[i].clear();
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dep[1] = 0; dfs(1, 0);
	for(int j = 1; j <= 20; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	
	int ans = 2e18;
	for(int mask = 1; mask < (1 << n); mask++)
	{
		if(__builtin_popcount(mask) != k) continue;
		fill(col + 1, col + n + 1, 0);
		
		vector<int> v;
		for(int i = 0; i < n; i++)
		{
			col[i + 1] = (mask >> i) & 1;
			if(col[i + 1]) v.push_back(i + 1);
		}
		cnt = 0;
		if(!dfs_check(1, 0)) continue;
		int mx = 0;
		for(int i = 1; i <= n; i++)
		{
			if(col[i]) continue;
			int res = 2e18;
			for(int x : v) res = min(res, calc(x, i));
			mx = max(mx, res);
		}
		ans = min(ans, mx);
	}
	cout << ans << endl;
	return;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> c >> t; 
	while(t--) solve();
	return 0;
}

