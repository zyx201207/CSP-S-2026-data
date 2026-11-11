#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

const int N = 505, M = 5e4 + 5;
int n, m, d, q;
int w[M];
vector <pii> g[M * 20];

vector <pii> past[M]; // p[i]: {i 被哪几条路线经过, 第几个经过}

int k[N], a[N][M], t[N][M];

int sd, td;
pii dis[M * 20];     // {起点到当前点的距离, 上一个点}
bool vis[M * 20];
priority_queue <pii> que;

int dij()
{
	for (int u = 1; u <= m; ++u)
	{
		for (int tt = 1; tt <= n; ++tt)
		{
			dis[u * d + tt] = {1e9, -1};
			vis[u * d + tt] = 0;
		}
	}
	for (int tt = 1; tt <= n; ++tt)
	{
		dis[sd * d + tt] = {0, -1};
		que.push({0, sd * d + tt});
	}
	
	while (que.size())
	{
		int u = que.top().second;
		que.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (auto nd : g[u])
		{
			int v = nd.first, w = nd.second;
			if (dis[u].first + w < dis[v].first)
			{
				dis[v] = {dis[u].first + w, u};
				que.push({-dis[v].first, v});
			}
		}
	}
	
	int ret = 1e9;
	for (int tt = 1; tt <= n; ++tt)
	{
		pii q = dis[td * d + tt];
		//cout << td * d + tt << " -> " << q.second << "\n";/////////////////
		
		int ot = 0;
		for (auto nd : g[td * d + tt])
		{
			if (nd.first == q.second)
			{
				ot = nd.second;
				break;
			}
		}
		
		ret = min(ret, q.first + ot);
	}
	return ret;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TTT;
	cin >> TTT >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
		{
			cin >> a[i][j] >> t[i][j];
			past[a[i][j]].push_back({i, j});
		}
			
		for (int au = 1; au < k[i]; ++au)
		{
			for (int b = au + 1; b <= k[i]; ++b)
			{
				int u = a[i][au] * d + i, v = a[i][b] * d + i;
				g[u].push_back({v, t[i][au]});
				g[v].push_back({u, t[i][b]});
			}
		}
	}
	
	for (int u = 1; u <= m; ++u)
	{
		for (auto pu : past[u])
		{
			for (auto pv : past[u])
			{
				g[u * d + pu.first].push_back({u * d + pv.first, 
					t[pu.first][pu.second]});
				
				g[u * d + pv.first].push_back({u * d + pu.first, 
					t[pv.first][pv.second]});
			}
		}
	}
	
	while (q--)
	{
		cin >> sd >> td;
		cout << dij() + w[sd] + w[td] << '\n';
	}
	return 0;
}
/*
0 2 5 10 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
