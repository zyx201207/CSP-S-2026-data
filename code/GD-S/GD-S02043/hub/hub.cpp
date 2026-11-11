#include<bits/stdc++.h>
using namespace std;

int n, k, ans, dis[110];
bool vis[110], viss[110];

vector <int> f[110];

void dfs(int x, int cnt, int p, int fa)
{
	if (viss[x]) return ;
	viss[x] = true;
	if (vis[x]) return ;
	if (cnt == k)
	{
		queue <int> q;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				q.push(i);
				dis[i] = 0;
			}
		}
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : f[u])
			{
				if (vis[v]) continue;
				if (dis[u] + 1 < dis[v])
				{
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		int maxx = INT_MIN;
		for (int i = 1; i <= n; i++) if (dis[i] != 1061109567 && dis[i] != 0) maxx = max(maxx, dis[i]);
		ans = min(ans, maxx);
		return ;
	}
//	cout << x << " " << cnt << " " << p << " " << fa << endl;
//	system("pause");
	if (vis[fa])
	{
		vis[x] = true;
		for (auto v : f[x])
		{
			if (v == fa || vis[v] || viss[v]) continue;
			dfs(v, cnt + 1, p, x);
		}
		vis[x] = false;
	}
	else if (p < 2)
	{
		vis[x] = true;
		for (auto v : f[x])
		{
			if (v == fa || vis[v] || viss[v]) continue;
			dfs(v, cnt + 1, p + 1, x);
		}
		vis[x] = false;
	}
	for (auto v : f[x]) dfs(v, cnt, p, x);
	
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		f[i].clear();
		vis[i] = false;
		viss[i] = false;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		f[u].emplace_back(v);
		f[v].emplace_back(u);
	}
	ans = INT_MAX;
	dfs(1, 0, 0, 0);
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
