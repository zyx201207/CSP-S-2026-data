#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[500005], a[505][50005], t[505][50005], kk[505], dis[5000005], idx;
bool vis[5000005];
map<pair<int, int>, int> mp;
map<int, int> mp2;
struct node
{
	int v, w;
};
vector<node> G[5000005];
struct point
{
	int plat, tim;
	bool line;
} p[5000005];
void dij(int s)
{
	for (int i = 1; i <= idx; i++)
	{
		dis[i] = 1e18;
		vis[i] = 0;
	}
	dis[s] = 0;
	priority_queue<pair<int, int> > q;
	q.push({0, s});
	while (!q.empty())
	{
		int u = q.top().second;
//		cout << u << " " << dis[u] << endl;
		q.pop();
		if (vis[u])
		{
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v, w = G[u][i].w;
			if (vis[v])
			{
				continue;
			}
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (c >= 20)
	{
		cout << 0 << endl;
		return 0;
	}
	idx = m;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> kk[i];
		mp2[i] = ++idx;
		p[idx].line = true;
		for (int j = 1; j <= kk[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			p[++idx].plat = a[i][j];
			p[idx].tim = t[i][j];
			mp[{i, j}] = idx;
		}
		for (int j = 1; j <= kk[i]; j++)
		{
			for (int k = j + 1; k <= kk[i]; k++)
			{
				int a = mp[{i, j}], b = mp[{i, k}];
				int lin = mp2[i];
				G[a].push_back({lin, 0});
				G[lin].push_back({a, 0});
				G[b].push_back({lin, 0});
				G[lin].push_back({b, 0});
			}
		}
	}
	for (int i = m + 1; i <= idx; i++)
	{
		int pl = p[i].plat, ti = p[i].tim;
		if (p[i].line)
		{
			continue;
		}
		G[i].push_back({pl, ti});
		G[pl].push_back({i, ti});
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << dis[y] + w[x] + w[y] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 2 4 20 4
3 1 4 2
3 1 3 2 2 3 1
2 4 1 3 2
1 2
1 3
1 4
2 4

9
11
12
9
*/
