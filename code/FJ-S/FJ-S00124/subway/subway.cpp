#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;//n为线路数,m为地铁口数 
int w[500005];
int k[500005];//第i条线路所经过的地铁数量 
vector<int> a[505],t[505];
int di[1005][1005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		a[i].push_back(-1);
		t[i].push_back(-1);
		for (int j = 1;j <= k[i];j++)
		{
			int x,y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for (int i = 1;i <= m + n;i++)
	{
		for (int j = 1;j <= m + n;j++)
		{
			di[i][j] = 1e18;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= k[i];j++)
		{
			di[i + m][a[i][j]] = t[i][j];
			di[a[i][j]][i + m] = t[i][j];
		}
	}
	for (int k = 1;k <= m + n;k++)
	{
		for (int i = 1;i <= m + n;i++)
		{
			for (int j = 1;j <= m + n;j++)
			{
				if (i == j || i == k || j == k)
				{
					continue;
				}
				if (di[i][k] + di[k][j] < di[i][j])
				{
					di[i][j] = di[i][k] + di[k][j];
				}
			}
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int l,r;
		cin >> l >> r;
		cout << di[l][r] + w[l] + w[r] << endl;
	}
	return 0;
}
