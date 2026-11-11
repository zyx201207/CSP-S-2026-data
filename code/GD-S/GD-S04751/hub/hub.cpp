#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, dep[2000005], fa[2000005][35];
vector<int> G[2000005];
void dfs(int u, int f)
{
	dep[u] = dep[f] + 1;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (v != f)
		{
			fa[v][0] = u;
			dfs(v, u);
		}
	}
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])
	{
		swap(u, v);
	}
	for (int i = 30; i >= 0; i--)
	{
		if (dep[fa[u][i]] >= dep[v])
		{
			u = fa[u][i];
		}
	}
	if (u == v)
	{
		return u;
	}
	for (int i = 30; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
int dist(int a, int b)
{
	int c = lca(a, b);
	return dep[a] + dep[b] - 2 * dep[c];
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			for (int j = 0; j <= 34; j++)
			{
				fa[i][j] = 0;
			}
		}
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		for (int i = 1; i <= 30; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				fa[j][i] = fa[fa[j][i - 1]][i - 1];
			}
		}
		vector<int> vec;
		for (int i = 1; i <= n; i++)
		{
			int minn = 1e9;
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				minn = min(minn, dist(i, j));
			}
			vec.push_back(minn);
		}
		sort(vec.begin(), vec.end(), greater<int>());
		cout << vec[k] << endl;
	}
	return 0;
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
