#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 5e3 + 5;
const long long INF = 1e18;
struct Edge
{
	int v, w;
};
vector<Edge> a[MAXN];
long long c, n, m, d, q, w[MAXM], dis[MAXM][MAXM];
void Floyd()
{
	for(int k = 1; k <= m; k++) 
		for(int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++) 
				if (dis[i][k] != INF && dis[k][j] != INF)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
} 
int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q; 
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
			dis[i][j] = INF;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x, t;
			cin >> x >> t;
			a[i].push_back((Edge){x, t});//aµØÌú   
		}
		for (int j = 0; j < k; j++)
			for (int l = j + 1; l < k; l++)
			{
				long long u = a[i][j].v, v = a[i][l].v, w = a[i][j].w + a[i][l].w;
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			} 
	}
	Floyd();
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << w[x] + dis[x][y] + w[y] << endl;
	}
	return 0;
} //O(n^3) 44
