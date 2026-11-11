#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d, a[2000005], dp[5005][5005], dpdp[5005][5005], ans;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		scanf("%lld %lld", &n, &d);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dp[i][j] = 0;
				dpdp[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			long long x = d, s = 1;
			for(int j = i + 1; j <= n; j++)
			{
				x -= a[j] - a[j - 1];
				if(x < 0)
				{
					s++;
					x = d;
					x -= a[j] - a[j - 1];
					if(x < 0)
					{
						break;
					}
				}
				dp[i][j] = s;
				dpdp[i][j] = 1;
			}
			dpdp[i][i] = 1;
		}
		ans = 0;
		for(long long i = 2; i <= n; i++)
		{
			for(long long l = 1, r = l + i - 1; r <= n; l++, r++)
			{
				long long cnt = 0;
				for(long long k = l; k <= r; k++)
				{
					if(a[k] - a[l] > d)
					{
						break;
					}
					if(1 + dp[k][r] == dp[l][r])
					{
						cnt += dpdp[k][r];
					}
					if(cnt > 2)
					{
						break;
					}
				}
				dpdp[l][r] = cnt;
				if(cnt == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
