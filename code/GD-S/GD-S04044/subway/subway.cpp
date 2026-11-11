#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2221;

int c, n, m, d, q;

int w[N];
int a[N][N], t[N][N];
int g[N][N];


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	memset(g, 0x3f, sizeof(g));
	
	for(int i = 1; i <= m; i++) cin >> w[i];
	
	for(int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
		for(int u = 1; u <= k; u++)
		{
			for(int v = 1; v <= k; v++)
			{
				if(u == v) g[a[i][u]][a[i][v]] = 0; 
				else g[a[i][u]][a[i][v]] = min(t[i][u] + t[i][v], g[a[i][u]][a[i][v]]);
			}
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= m; k++)
			{
				if(i != j && i != k && j != k)
				{
					if(g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}
	
	for(int i = 1, u, v; i <= q; i++)
	{
		cin >> u >> v;
		cout << g[u][v] + w[u] + w[v] << "\n";
	}
	
	return 0;
}
