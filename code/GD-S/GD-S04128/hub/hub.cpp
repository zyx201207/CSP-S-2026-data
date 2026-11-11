#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5, maxm = 2 * 1e1 + 5;
int c, t, n, k, cnt, dep[maxn], f[maxn][maxm];
bool vis[maxn], isp[maxn];
vector<int> G[maxn];
void dfss(int u)
{
	isp[u] = true;
	for (auto v : G[u])
	{
		if (vis[v] == false)
		{
			continue;
		}
		if (isp[v] == false)
		{
			dfss(v);
		}
	}
}
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 1; i < maxm; ++ i)
	{
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for (auto v : G[u])
	{
		if (v == fa)
		{
			continue;
		}
		dfs(v, u);
	}
}
int lca(int x, int y)
{
	int ret = 0;
	if (dep[x] < dep[y])
	{
		swap(x, y);
	}
	for (int i = maxm - 1; i >= 0; -- i)
	{
		if (dep[f[x][i]] >= dep[y])
		{
			x = f[x][i];
			ret += (1 << i);
		}
	}
	if (x == y)
	{
		return ret;
	}
	for (int i = maxm - 1; i >= 0; -- i)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
			ret += (1 << i);
		}
	}
	return ret + 1;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		memset(dep, 0, sizeof dep);
		memset(f, 0, sizeof f);
		int res = INT_MAX;
		cnt = 0;
		for (int i = 0; i <= n; ++ i)
		{
			G[i].clear();
		}
		cin >> n >> k;
		for (int i = 1; i < n; ++ i)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		for (int i = 0; i < (1 << n); ++ i)
		{
			cnt = 0;
			if (__builtin_popcount(i) != k)
			{
				continue;
			}
			memset(vis, 0, sizeof vis);
			memset(isp, 0, sizeof isp);
			for (int j = 1; j <= n; ++ j)
			{
				if ((i & (1 << (j - 1))) != 0)
				{
					vis[j] = true;
				}
			}
			bool f = true;
			for (int j = 1; j <= n; ++ j)
			{
				if (vis[j] == false)
				{
					continue;
				}
				if (isp[j] == false)
				{
					if (cnt >= 2)
					{
						f = false;
						break;
					}
					++ cnt;
					dfss(j);
				}
			}
			if (f == false)
			{
				continue;
			}
			int out = INT_MIN;
			for (int j = 1; j <= n; ++ j)
			{
				int ans = INT_MAX;
				for (int L = 1; L <= n; ++ L)
				{
					if (vis[L] == true)
					{
						ans = min(ans, lca(j, L));
					}
				}
				//cout << j << " " << ans << endl;
				out = max(out, ans);
			}
			res = min(res, out);
		}
		cout << res << endl;
	}
	return 0;
}

