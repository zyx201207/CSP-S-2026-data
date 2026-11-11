#include <bits/stdc++.h>
using namespace std;

int bfs(int st, vector < vector < int > >& dist, int n, const vector < int >& dis, int d)
{
	int ret = 0;
	queue < pair < int , int > > q;
	vector < bool > vis(n);
	q.push({st, 0});
	while (!q.empty())
	{
		int u = q.front().first, len = q.front().second;
		q.pop();
		vis[u] = 1;
		dist[st][u] = len;
		int di = 0;
		for (int v = u + 1; v < n; v++)
		{
			di += dis[v - 1];
			if (di <= d)
			{
				if (!vis[v])
					q.push({v, len + 1});
				else if (vis[v] && dist[st][v] == len + 1) ret++;
				//cerr << (dist[st][v] == len + 1) << " " << dist[st][v] << " " << len + 1 << endl;
			}
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	
	if (1)
	{
		while (t--)
		{
			int n, d;
			cin >> n >> d;
			vector < int > island(n);
			vector < int > dis(n - 1);
			for (int i = 0; i < n; i++)
			{
				cin >> island[i];
				if (i != 0) dis[i - 1] = island[i] - island[i - 1];
			}
			
			vector < vector < int > > dist(n, vector < int > (n));
			
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				ans += bfs(i, dist, n, dis, d);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
