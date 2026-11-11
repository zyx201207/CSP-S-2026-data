#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M];
ll dis[N][N];
vector<int> p[M];
unordered_map<int, int> ot[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int x, v;
			cin >> x >> v;
			ot[i][x] = v;
			p[x].push_back(i);
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			dis[i][j] = (i == j ? 0 : 1e16);
	for(int i = 1;i <= m;i++)
		for(int j = 0;j < p[i].size();j++)
			for(int k = j + 1;k < p[i].size();k++)
			{
				int u = p[i][j], v = p[i][k];
				dis[u][v] = min(dis[u][v], 1ll * ot[u][i] + ot[v][i]);
				dis[v][u] = dis[u][v];
			}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			if(i != k)
				for(int j = 1;j <= n;j++)
				{
					if(i == j || j == k) continue;
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
	while(q--)
	{
		int u, v;
		ll ans = 1e18;
		cin >> u >> v;
		for(int i = 0;i < p[u].size();i++)
			for(int j = 0;j < p[v].size();j++)
			{
				int a = p[u][i], b = p[v][j];
				ans = min(ans, dis[a][b] + ot[a][u] + ot[b][v]);
			}
		cout << ans + w[u] + w[v] << "\n";
	}
	return 0;
}
