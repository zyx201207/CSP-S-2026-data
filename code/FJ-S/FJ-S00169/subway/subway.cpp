#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair <int, int>
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5, D = 25, INF = 1e18;
struct Edge
{
	int v,w;
};
vector <Edge> e[N];
vector <PII> stk[M];
int c, n, m, d, q, x, y, ans, w[M],  k[N], a[N][D], t[N][D],dis[N][N];
void solve()
{
	cin >> c >> n >> m >> d >> q;
	for (int i =1; i <= n; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			dis[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		dis[i][i] = 0;
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			stk[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m;i++)
	{
		for (int u = 0; u < (int)(stk[i].size());u++)
		{
			for (int v = u + 1;v < (int)(stk[i].size());v++)
			{
				int scc1 = stk[i][u].first;
				int scc2 = stk[i][v].first;
				int t1 = stk[i][u].second;
				int t2 = stk[i][v].second;
				dis[scc1][scc2] = min(dis[scc1][scc2], t1 + t2);
				dis[scc2][scc1] = min(dis[scc2][scc1], t1 + t2);
			}
		}
	}
	for (int k = 1;k <=n; k++)
	{
		for (int i= 1; i <=n; i++)
		{
			for (int j=1; j <=n;j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k]+ dis[k][j]);
			}
		}
	}
	while (q--)
	{
		cin >> x >> y;
		int res= INF;
		for (int u = 0; u < (int)(stk[x].size());u++)
		{
			for (int v = 0;v < (int)(stk[y].size());v++)
			{
				if ( res > stk[x][u].second + stk[y][v].second + dis[stk[x][u].first][stk[y][v].first])
	            {
	            	res = stk[x][u].second + stk[y][v].second + dis[stk[x][u].first][stk[y][v].first];
	            	//cout << stk[x][u].first << ' ' << stk[y][v].first << endl;
				}
			}
		}
		//cout << res << endl;
		cout <<w[x] + w[y] + res << endl;
	}
	return;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}