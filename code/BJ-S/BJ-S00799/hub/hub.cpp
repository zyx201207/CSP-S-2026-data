#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int c, t, n, k, u, v, ans = 1e9, dis[N][N];
vector <int> g[N];
set <int> s;
bool vis[N];

void check(int x)
{
	queue <int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v: g[u])
			if (!vis[v] && s.count(v))
				q.push(v), vis[v] = true;
	}
}

void dfs(int u, int dep)
{
	if (dep > k)
	{
		fill(vis+1, vis+n+1, false);
		int cnt = 0, now = 0;
		for (auto v: s)
			if (!vis[v])
			{
				if (cnt >= 2)
					return;
				check(v);
				cnt++;
			}
		for (int i = 1; i <= n; i++)
		{
			if (s.count(i))
				continue;
			int mn = 1e9;
			for (auto v: s)
				mn = min(mn, dis[i][v]);
			now = max(now, mn);
		}
		ans = min(ans, now);
		return;
	}
	s.insert(u);
	for (int i = 1; i <= n; i++)
		if (!s.count(i))
		{
			dfs(i, dep+1);
			s.erase(i);
		}
}

void makedis(int x)
{
	queue <int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v: g[u])
			if (!vis[v])
			{
				q.push(v);
				dis[x][v] = dis[x][u]+1;
				vis[v] = true;
			}
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		ans = 1e9;
		cin >> n >> k;
		s.clear();
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			fill(vis+1, vis+n+1, false);
			makedis(i);
		}
		dfs(1, 1);
		cout << ans << '\n';
	}
	return 0;
}