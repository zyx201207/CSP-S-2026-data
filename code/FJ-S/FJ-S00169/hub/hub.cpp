#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 5, M = 1e3 + 5,INF = 1e18;
struct Node
{
	int u, w;
	bool operator < (const Node &other) const
	{
		return w < other.w;
	}
};
vector <int> e[M];
int c, t, n, k, dis[M][M], d[M],ans;
bool vis[M][M],use[M], no[M];
void bfs(int st)
{
	queue <int> q;
	q.push(st);
	dis[st][st] = 0;
	vis[st][st] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : e[u])
		{
			if (!vis[st][v])
			{
				dis[st][v] = dis[st][u] + 1;
				vis[st][v] = 1;
				q.push(v);
			}
		}
	}
	return;
}
void wyt(int cnt)
{
	if (cnt > k) return;
	if (cnt == k)
	{
		int res=-INF;
		for (int i = 1;i<= n; i++)
		{
			d[i] = INF;
			for (int j = 1;j <= n; j++)
			{
				if(use[j])
				    d[i] = min(d[i], dis[i][j]);
			}
		}
		for (int i=1; i<= n; i++)
		{
			res = max(d[i], res);
		}
		//if (use[2] && use[7] && use[9]) cout << res<<endl;
		if (ans > res)
		{
			ans = res;
		}
		return;
	}
	for (int i= 1;i<=n; i++)
	{
		if (use[i])
		{
			for (auto j : e[i])
			{
				if (use[j]) continue;
				use[j] = true;
				wyt(cnt + 1);
				use[j] = false;
			}
		}
	}
	return;
}
void solve()
{
	cin >> n >> k;
	for (int i = 1;i < n; i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i= 1;i<=n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vis[i][j] = false;
			dis[i][j] = INF;
		}
	}
	for (int i = 1; i<= n;i++)
	    bfs(i);
	ans = INF;
	for(int i =1; i <= n; i++)
	{
		for (int j =1; j <= n; j++)
		{
			use[i] = use[j] =1;
			if (i != j) wyt(2);
			else wyt(1);
			use[i] = use[j] =0;
		}
	}
	cout << ans << endl;
	return;
}
signed main()
{
	freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}