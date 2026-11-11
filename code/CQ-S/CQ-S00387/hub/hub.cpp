#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
int c, T, n, k, x, y, s, v[1000005], fa[1000005], d[1000005];
int get(int x)
{
	if (fa[x] != x)
	{
		fa[x] = get(fa[x]);
	}
	return fa[x];
}
void merge(int x, int y)
{
	x = get(x);
	y = get(y);
	fa[x] = y;
}
void dfs(int x, int z)
{
	if (x > n)
	{
		if (z != 0)
		{
			return ;
		}
		for (int i = 1; i <= n; i++)
		{
			if (v[i] == 1)
			{
				fa[i] = i;
			}	
		}
		for (int i = 1; i <= n; i++)
		{
			if (v[i] == 1)
			{
				for (int j = 0; j < (int)g[i].size(); j++)
				{
					int y = g[i][j];
					if (v[y] == 0)
					{
						continue;
					}
					merge(i, y);
				}
			}
		}
		int sz = 0;
		for (int i = 1; i <= n; i++)
		{
			if (v[i] == 1)
			{
				if (fa[i] == i)
				{
					sz++;
				}
			}
		}
		if (sz > 2)
		{
			return ;
		}
		queue<int> q;
		int ss = 0;
		for (int i = 1; i <= n; i++)
		{
			d[i] = -1;
			if (v[i] == 1)
			{
				d[i] = 0;
				q.push(i);
			}
		}
		while (q.size())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < (int)g[x].size(); i++)
			{
				int y = g[x][i];
				if (d[y] != -1)
				{
					continue;
				}
				d[y] = d[x] + 1;
				ss = max(ss, d[y]);
				q.push(y);
			}
		}
		s = min(s, ss);
		return ;
	}
	dfs(x + 1, z);
	if (z)
	{
		v[x] = 1;
		dfs(x + 1, z - 1);
		v[x] = 0;
	}
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		for (int i = 1; i <= n; i++)
		{
			g[i].clear();
		}
		cin >> n >> k;
		s = INT_MAX;
		for (int i = 1; i < n; i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (n <= 10)
		{
			dfs(1, k);
			cout << s << "\n";
			continue;
		}
	}
	return 0;
}
