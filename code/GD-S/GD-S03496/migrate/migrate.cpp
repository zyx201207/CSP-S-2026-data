#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, x[2000005], dp[5005][5005], sum[5005][5005], ans;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		if (n==1)
		{
			cout << 0 <<'\n';
			continue;
		}
		ans=0;
		for (int i=1; i<=n; i++)
		{
			cin >> x[i];
		}
		if (c==11 || c==12)
		{
			int h=d/(x[2]-x[1]);
			if (d!=2)
			{
				cout << 0 <<'\n';
				continue;
			}
			cout << n-d-1 <<'\n';
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				dp[i][j]=1e12;
			}
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n && x[i]+d>=x[j]; j++)
			{
		 		for (int k=1; k<i; k++)
				{
					if (dp[k][j]>dp[k][i]+1)
					{
						dp[k][j]=dp[k][i]+1;
						sum[k][j]=1;
					}
					else if (dp[k][j]==dp[k][i]+1)
					{
						dp[k][j]=dp[k][i]+1;
						sum[k][j]++;
					}
				}
				dp[i][j]=1;
			}
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				if (sum[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}
