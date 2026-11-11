#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;//线路数，站数，最多几个线路，计划数
int w[500010],edge[10002][10002],k[510],a[510][25],t[510][25];
signed main()
{
	//cout << ((500010 + (10002 * 10002) + 510 + ((510 * 25) * 2)) * 8) / 1024 / 1024;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	memset(edge,0x3f,sizeof(edge));
	for (int i = 1;i <= m;i++)
	{
		edge[i][i] = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= k[i];j++)//对于每个站的遍历建图 
		{
			for (int p = 1;p <= k[i];p++)
			{
				if (a[i][j] != a[i][p])
				{
					edge[a[i][j]][a[i][p]] = t[i][j] + t[i][p];
					//cout << "!!" << a[i][j] << "!!!" << a[i][p] << '\n';
				}
				else
				{
					edge[a[i][j]][a[i][p]] = 0;
				}
			}
		}
	}
	for (int p = 1;p <= m;p++)
	{
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				//cout << "!!" << i << ' '<< j << ' ' << p << "!!!" << edge[i][j] << ' ' << edge[i][p] << ' ' << edge[p][j] << endl;
				if (edge[i][j] > edge[i][p] + edge[p][j])
				{
				//	cout << "!!!";
					edge[i][j] = edge[i][p] + edge[p][j];
				}
			}
		}
	}
	/*
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			printf("%.4ld ",edge[i][j]);
		}
		cout << '\n';
	}
	*/
	int x,y;
	for (int i = 1;i <= q;i++)
	{
		cin >> x >> y;
		cout << w[x] + w[y] + edge[x][y] << '\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
