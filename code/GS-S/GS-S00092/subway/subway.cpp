#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n , m , d , q , k , a , t , ans;
	cin >> c >> n >> m >> d >> q;
	int w[m + 1] , r[m + 1] , rp[n + 1][n + 1];
	long long f[n - 1][n - 1];
	vector<int> tag , lin[n + 1] , e[n + 1];
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			cin >> a >> t;
			r[a] += t;
			lin[i].push_back(a);
		}
	}
	memset(rp , 0 , sizeof(rp));
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			for (int o = 0;o < lin[i].size();o++)
			{
				for (int p = 0;p < lin[j].size();p++)
				{
					if(lin[i][o] == lin[j][p])
					{
						rp[i][j] = rp[j][i] = max(rp[i][j] , r[lin[i][o]]);
						e[i].push_back(j);
						e[j].push_back(i);
					}
				}
			}
		}
	}
	for (int i = 1;i <= n;i++)
		f[i][i] = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int v = 0;v < e[i].size();v++)
			{
				if (e[i][v] == j)
					f[i][j] = rp[i][j];
				else
					f[i][j] = 0x7f;
			}
		}
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
	while(q--)
	{
		ans = 0;
		int x , y , xx , yy;
		cin >> x >> y;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 0;j < lin[i].size();j++)
			{
				if (lin[i][j] == x)
					xx = i;
				if (lin[i][j] == y)
					yy = i;
			}
		}
		if (xx == yy)
			ans = r[x] + r[y] + w[x] + w[y];
		else
			ans = w[x] + w[y] + f[x][y] + r[x] + r[y];
		cout << ans << "\n";
	}
	return 0;
}
