#include <bits/stdc++.h>
using namespace std;
#define int long long 
int c,T;
int n,d;
int a[5005];
int w[5005][5005];
int nxt[5005][5005];
int cnt[5005][5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		int ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= 5001;i++)
		{
			for (int j = 1;j <= 5001;j++)
			{
				w[i][j] = 2 * 1e18;
			}
		}
		for (int i = 1;i <= 5001;i++)
		{
			for (int j = 1;j <= 5001;j++)
			{
				nxt[i][j] = 2 * 1e18;
			}
		}
		for (int i = 1;i <= 5001;i++)
		{
			for (int j = 1;j <= 5001;j++)
			{
				cnt[i][j] = 0;
				if (i == j)
				{
					cnt[i][i] = 1;
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				if (a[j] - a[i] <= d)
				{
					w[i][j] = 1;
					nxt[i][j] = 1;
					cnt[i][j] = 1;
				}
			}
		}
		for (int k = 1;k <= n;k++)
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = i + 1;j <= n;j++)
				{
					if (i == k || j == k)
					{
						continue;
					}
					if (w[i][k] + w[k][j] < w[i][j])
					{
						w[i][j] = w[i][k] + w[k][j];
					}
				}
			}
		}
		for (int k = 1;k <= n;k++)
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = i + 1;j <= n;j++)
				{
					if (i == k || j == k)
					{
						continue;
					}
					if (nxt[i][k] + nxt[k][j] < nxt[i][j])
					{
						nxt[i][j] = nxt[i][k] + nxt[k][j];
						cnt[i][j] = 0;
					}
					if (nxt[i][k] + nxt[k][j] == w[i][j])
					{
						cnt[i][j]++;
					}
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				if (cnt[i][j] == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
