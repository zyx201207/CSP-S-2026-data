#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int x, y;
};

int c, t, n, k, a, b, dis[1005][1005], maxn[1005], maxx[1005];
vector<int> g[1005];

bool operator < (node x, node y)
{
	return x.x > y.x;
}

void dijkstra(int s)
{
	priority_queue<node> q;
	q.push({s, 0});
	memset(dis[s], 0x3f, sizeof dis[s]);
	dis[s][s] = 0;
	while (q.size())
	{
		node t = q.top();
		q.pop();
		if (dis[s][t.x] != t.y) continue;
		for (int x : g[t.x])
			if (dis[s][x] > dis[s][t.x] + 1)
			{
				dis[s][x] = dis[s][t.x] + 1;
				q.push({x, dis[s][x]});
			}
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) g[i].clear();
		memset(maxn, 0, sizeof maxn);
		int ans = 2e9;
		for (int i = 1; i < n; ++i)
		{
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 1; i <= n; ++i) dijkstra(i);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (dis[i][j] > maxn[i]) maxn[i] = dis[i][j], maxx[i] = j;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) ans = min(ans, max(max(dis[i][j] / 2, dis[i][maxx[j]]), dis[maxx[i]][j]));
		cout << ans << '\n';
	}
	return 0;
}