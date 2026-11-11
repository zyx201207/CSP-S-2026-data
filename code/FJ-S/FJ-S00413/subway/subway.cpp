# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 3e4, M = 6e5;
int c, n, m, d, q;
int w[M];
vector < pair < int, int > > g[M];
bool vis[M];
int dis[505][N];
signed dist[505][M];
int _dis[3][N];
vector < pair < int, int > > station[N];
void dijkstra(int s)
{
	memset(vis, 0, sizeof vis);
	priority_queue < pair < int, int > > q;
	q.push({0, s});
	dis[s - m][s] = 0;
	while (!q.empty())
	{
		auto _ = q.top();
		int u = _.second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto __ : g[u])
		{
			int v = __.first;
			int w = __.second;
			if (dis[s - m][v] > dis[s - m][u] + w)
			{
				dis[s - m][v] = dis[s - m][u] + w;
				q.push({-dis[s - m][v], v});
			}
		}
	} 
}
void dijkstra2(int s)
{
	memset(vis, 0, sizeof vis);
	priority_queue < pair < int, int > > q;
	q.push({0, s});
	_dis[s - m][s] = 0;
	while (!q.empty())
	{
		auto _ = q.top();
		int u = _.second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto __ : g[u])
		{
			int v = __.first;
			int w = __.second;
			if (_dis[s - m][v] > _dis[s - m][u] + w)
			{
				_dis[s - m][v] = _dis[s - m][u] + w;
				q.push({-dis[s - m][v], v});
			}
		}
	} 
}
void bfs(int s)
{
	memset(vis, 0, sizeof vis);
	queue < int > q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto _ : g[u])
		{
			int v = _.second;
			if (!vis[v])
			{
				q.push(v);
				dis[s - m][v] = dis[s - m][u] + 1;
			}
		}
	}
}
void solve()
{
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i ++)
	{
		cin >> k;
		for (int j = 1, a, t; j <= k; j ++)
		{
			cin >> a >> t;
			station[a].push_back({i, t});
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	if (c <= 15)
	{
		memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= n; i ++) dijkstra(m + i);
		while (q --)
		{
			int x, y;
			cin >> x >> y;
			int ans = 1e18;
			for (auto _ : station[x])
			{
				int s = _.first;
				int val = _.second;
				ans = min(ans, w[x] + val + dis[s][y] + w[y]);
			}
			cout << ans << '\n';
		}
	}
	else if (c >= 16 && c <= 19)
	{
		for (int i = 1; i <= n; i ++) bfs(m + i);
		while (q --)
		{
			int x, y;
			cin >> x >> y;
			int ans = 1e18;
			for (auto _ : station[x])
			{
				int s = _.first;
				int val = _.second;
				ans = min(ans, w[x] + val + 1ll * dist[s][y] * val + w[y]);
			}
			cout << ans << '\n';
		}
	}
	else if (c >= 20 && c <= 21)
	{
		memset(_dis, 0x3f, sizeof _dis);
		for (int i = 1; i <= n; i ++) dijkstra2(m + i);
		while (q --)
		{
			int x, y;
			cin >> x >> y;
			int ans = 1e18;
			for (auto _ : station[x])
			{
				int s = _.first;
				int val = _.second;
				ans = min(ans, w[x] + val + _dis[s][y] + w[y]);
			}
			cout << ans << '\n';
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while (T --) solve();
	return 0;
}

