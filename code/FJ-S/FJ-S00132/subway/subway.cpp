#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
const int N = 10005;
int c, n, m, d, q, w[N], t[20][N], a[20][N], x[N], y[N], k[N];
struct Station
{
	int id, w, t;
}
vector <Station> station[2][20][N];
int dfs(int x, int y)
{
	int ans = 0;
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k1 = 1; k1 <= k[j]; k1++)
			{
				for (int c = 0; c < station[i][j][k1].size(); c++)
				{
					int v = station[i][j][k1][c];
					if (d[ans] > d[v] + station[i][j][k1].w)
						return ans;
					dfs(x, v);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> station[2][i][j].w;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> station[2][i][j].id >> station[2][i][j].t;
		}
	} 
	for (int i = 1; i <= q; i++)
	{
		for (int j = 1; j <= k[i]; j++)
		{
			station[1][i][j] = station[2][i][j];
			station[2][i][j].push_back(station[1][i][j]{id, w, t});
			station[1][i][j].push_back(station[2][i][j]{id, w, t});
		}	
	}
	for (int i = 1; i <= d; i++)
	{
		for (int j = i; j <= d; j++)
		{
			for (int k1 = 1; k1 <= k[i], k1++)
			{
				if (station[2][i][k] = station[2][j][k])
				{
					station[1][j][k].push_back(station[2][i][k]);
					station[2][i][k].push_back(station[1][j][k]);
					station[1][i][k].push_back(station[2][j][k]);
					station[2][j][k].push_back(station[1][i][k]);
				}
			}
		}
	} 
	for (int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];
		cout << dfs(x[i], y[i]);
	}
	return 0;
}
