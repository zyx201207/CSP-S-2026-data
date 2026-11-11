#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 505;
vector <pair<int,int> > e[N];
int w[N], dis[N], vis[N], k;
int c, n, m, d, Q;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

int dijkstra(int start, int end)
{
	int ans;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[start] = 0;
	q.push({dis[start], start});
	while(!q.empty())
	{
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < e[u].size(); i++)
		{
			int v = e[u][i].first, w = e[u][i].second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
			if (v == end) break;
		}
	} 
	ans = dis[end] + w[start] + w[end];
	return ans;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, b;
			cin >> a >> b;
			e[N - i].push_back({a, b});
			e[a].push_back({N - i, b});
		}
	}
	for (int i = 1; i <= Q; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << dijkstra(x, y) << '\n';
	}
	return 0;
}
