#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], a[505][200005], t[505][200005], um, x, y, f[5005][5005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> um;
		for (int j = 1; j <= um; j++)
		{
			cin >> a[i][j] >> t[i][j];
			f[a[i][j - 1]][a[i][j]] = f[a[i][j]][a[i][j - 1]] = w[j - 1] + t[i][j - 1] + t[i][j] + w[j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = i + 1; j <= m; j++)
			{
				if (f[i][j] == 0)
				{
					f[i][j] = f[i][k] + f[k][j];
					continue;
				}
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		cout << f[x][y] << endl;
	}
	return 0;
}
/*
n个线路，m个站，k[i]表示第i条线路的地铁站数
a[i][j]第i条线路的第j个站，t[i][j]第i条线路的第j个站沟通站厅到第i条线路的站台的距离，w[i]第i个站地铁口到站厅 
*/
