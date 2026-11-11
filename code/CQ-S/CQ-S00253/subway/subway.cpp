#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 5e5 + 5;
const int M = 505;
const ll inf = 1000000000000000000LL;
int c, n, m, d, q;
ll w[N];
//vector<pair<int, ll>> graph[N];
vector<pair<int, ll>> edges[N];
ll dist[M][M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = inf;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x;
			ll t;
			cin >> x >> t;
			edges[x].push_back({i, t});
//			graph[i].push_back({x, t});
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto a : edges[i])
		{
			ll ax = a.first, at = a.second;
			for (auto b : edges[i])
			{
//				cout << "#"; 
				ll bx = b.first, bt = b.second;
				if (ax == bx) continue;
//				cout << ax << " " << bx << "\n";
				dist[ax][bx] = dist[bx][ax] = min(dist[ax][bx], at + bt);
			}
		}
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		ll res = inf;
		for (auto a : edges[x])
			for (auto b : edges[y])
				res = min(res, a.second + b.second + dist[a.first][b.first]);
		 res += w[x] + w[y];
		 cout << res << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

