#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define pii pair<int, int>
int c, n, m, d, q;
//vector<pii> g[505]; // railway -> station
int w[500005];
vector<pii> cop[500005]; // station -> railway
int dis[505][505];
int dist[505];
//bool vis[505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int v, w;
			cin >> v >> w;
//			g[i].push_back({v, w});
			cop[v].push_back({i, w});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	int st = 0;
	for (int i = 1; i <= m; i++)
	{
		int sz = cop[i].size();
		for (int l = 0; l < sz - 1; l++)
			for (int r = l + 1; r < sz; r++)
			{
				pii ll = cop[i][l], rr = cop[i][r];
				st = ll.first;
				dis[ll.first][rr.first] = min(ll.second + rr.second, dis[ll.first][rr.first]);
				dis[rr.first][ll.first] = dis[ll.first][rr.first];
			}
	}
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		int usz = cop[u].size(), vsz = cop[v].size();
		int ans = 1e9;
		for (int i = 0; i < usz; i++)
		{
			memset(dist, 0x3f, sizeof dist);
			priority_queue<pii, vector<pii>, greater<pii>> pq;
			int uu = cop[u][i].first;
			dist[uu] = 0;
			pq.push({0, uu});
			while (!pq.empty())
			{
				pii nw = pq.top();
				int w = nw.first;
				int nww = nw.second;
				pq.pop();
				for (int nxt = 1; nxt <= n; nxt++)
				{
					if (dis[nww][nxt] == 0x3f3f3f3f)
						continue;
					if (dist[nxt] > dist[nww] + dis[nww][nxt])
					{
						dist[nxt] = dist[nww] + dis[nww][nxt];
						pq.push({dist[nxt], nxt});
					}
				}
			}
			for (int j = 0; j < vsz; j++)
				ans = min(ans, dist[cop[v][j].first] + cop[u][i].second + cop[v][j].second);
		}
		cout << ans + w[u] + w[v] << endl;
	}
}
//fc D:\noip\HE-S00023\subway\subway.out D:\noip\HE-S00023\subway\subway3.ans
