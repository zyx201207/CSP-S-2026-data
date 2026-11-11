#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 7;
const int N1 = 5e5 + 7;
long long c,n,m,d1,q,w[N],dp[507][N],zd[507][507];
long long f[N1],k1,k2,f1[N1];
deque<long long> d[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(zd,0x3f3f3f3f3f3f3f3f,sizeof(zd));
	cin >> c >> n >> m >> d1 >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	if (n <= 2)
	{
		if (n == 1)
		{
			int k;
			cin >> k;
			for (int i = 1,gm;i <= 2 * k;i++)
			{
				cin >> gm;
			}
			for (int i = 1,x,y;i <= q;i++)
			{
				cin >> x >> y;
				cout << w[x] + w[y] << endl;
			}
			return 0;
		}
		
		memset(f,0,sizeof(f));
		cin >> k1;
		for (int i = 1,x,t;i <= k1;i++)
		{
			cin >> x >> t;
			f[x] = 1;
			f1[x] += t;
		}
		cin >> k2;
		for (int i = 1,x,t;i <= k2;i++)
		{
			cin >> x >> t;
			f[x] = (f[x] == 1 ? 3 : 2);
			f1[x] += t;
		}
		long long sum = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1;i <= m;i++)
		{
			if (f[i] == 3)
			{
				sum = min(sum,f1[i]);
			}
		}
		for (int i = 1,x,y;i <= q;i++)
		{
			cin >> x >> y;
			if ((f[x] == 1 && f[y] == 2) || (f[x] == 2 && f[y] == 1))
			{
				cout << w[x] + w[y] + sum << endl;
			}
			else
			{
				cout << w[x] + w[y] << endl;
			}
		}
		return 0;
	}
	for (int i = 1,k;i <= n;i++)
	{
		cin >> k;
		for (int j = 1,x,t;j <= k;j++)
		{
			cin >> x >> t;
			dp[i][x] = t;
			d[x].push_back(i);
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 0;j < d[i].size();j++)
		{
			for (int k = j + 1;k < d[i].size();k++)
			{
				zd[d[i][j]][d[i][k]] = min(zd[d[i][j]][d[i][k]],dp[d[i][j]][i] + dp[d[i][k]][i]);
				zd[d[i][k]][d[i][j]] = min(zd[d[i][k]][d[i][j]],dp[d[i][j]][i] + dp[d[i][k]][i]);
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		zd[i][i] = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= n;k++)
			{
				zd[j][k] = min(zd[j][k],zd[j][i] + zd[i][k]);
			}
		}
	}
	for (int i = 1,x,y;i <= q;i++)
	{
		long long ans = 0x3f3f3f3f3f3f3f3f;
		cin >> x >> y;
		for (int j = 0;j < d[x].size();j++)
		{
			for (int k = 0;k < d[y].size();k++)
			{
				ans = min(ans,dp[d[x][j]][x] + zd[d[x][j]][d[y][k]] + dp[d[y][k]][y]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
} 
