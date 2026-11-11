#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 505, M = 500005;
int c, n, m, d, q, w[M], cnt;
vector <pair<int, int> > e[N];
int g[N][N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
		cin >> w[i];
	
	for(int i = 1 ; i <= n ; i++)
	{
		int k;
		cin >> k;
		for(int j = 1 ; j <= k ; j++)
		{
			int u, v, w;
			cin >> v >> w;
			u = i + m;
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}
	}
	
	memset(g, 0x3f, sizeof(g));
	for(int i = 1 ; i <= n + m ; i++)
		g[i][i] = 0;
		
	for(int k = 1 ; k <= m ; k++)
	{
		if(e[k].size() > 1)
		{
			int kn = e[k].size();
			for(int i = 0 ; i < kn ; i++)
			{
				int u = e[k][i].first;
				int w1 = e[k][i].second;
				for(int j = i + 1 ; j < kn ; j++)
				{
					int v = e[k][j].first;
					int w2 = e[k][j].second;
					if(g[u][v] > w1 + w2)
					{
						g[u][v] = w1 + w2;
						//cout << u << " " << v << " :" << w1 + w2 << "\n";
					}
					
				}
			}
		}
	}
	for(int k = m + 1 ; k <= m + n ; k++)
	{
		for(int i = m + 1 ; i <= m + n ; i++)
		{
			for(int j = m + 1 ; j <= m + n ; j++)
			{
				g[i][j] = g[j][i] = min(g[i][j], g[j][i]);
				if(g[i][j] > g[i][k] + g[k][j])
				{
					g[i][j] = g[j][i] = g[i][k] + g[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int l, r, minn = 2e9;
		cin >> l >> r;
		for(int i = 0 ; i < (int)e[l].size() ; i++)
		{
			for(int j = 0 ; j < (int)e[r].size() ; j++)
			{
				int u = e[l][i].first;
				int v = e[r][j].first;
				int u1 = e[l][i].second;
				int v1 = e[r][j].second;
				minn = min(minn, w[l] + w[r] + g[u][v] + u1 + v1);
			}
		}
		cout << minn << "\n";
	}
	
	return 0;
}
