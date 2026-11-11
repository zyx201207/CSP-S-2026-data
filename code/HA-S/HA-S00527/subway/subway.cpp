#include <bits/stdc++.h>
#define  int long long
using namespace std;
const int maxn = 5e5 + 100;

int c ,n ,m ,d ,q;
vector <pair <long long ,long long> > adj[maxn];
int dist[maxn];
bool vis[maxn];
int cnt = 1;

void dijkstra(int st ,int ed)
{
	memset(dist ,0x3f ,sizeof dist);
	memset(vis ,false ,sizeof vis);
	priority_queue <pair <int ,int> ,vector <pair <int ,int> > ,greater<pair <int ,int> > > q;
	q.push({0 ,st});
	dist[st] = 0;
	vis[st] = true;
	while (!q.empty())
	{
		int u = q.top().second;
		if (u == ed)
		{
			cout << dist[u] << '\n';
			return ;
		}
		q.pop();
		//if (vis[u]) continue;
		vis[u] = true;
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
			if (!vis[v])
			{
				
				vis[v] = true;
				q.push({dist[v] ,v});
			}
		}
	}
}

signed main()
{
	freopen("subway.in" ,"r" ,stdin);
	freopen("subway.out" ,"w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		int w;
		cin >> w;
		adj[i].push_back({m + i ,w});
		adj[m + i].push_back({i ,w});
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int node ,w;
			cin >> node >> w;
			adj[2 * m + i].push_back({m + node ,w});
			adj[m + node].push_back({2 * m + i ,w});
		}
	}
	while (q--)
	{
		int u ,v;
		cin >> u >> v;
		dijkstra(u ,v);
	}
	
	return 0;
}
