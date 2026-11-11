#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005] = {1};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= 30;i++) dp[0] *= 2;
	dp[0]--;
	if(m == 1) cout << a[n];
	else if(m == n)
	{
		for(int i = 1;i <= n;i++) dp[0] &= a[i];
		cout << dp[0];
	}
	else if(m == n - 1)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j) continue;
				else dp[0] &= a[i];
			}
		}
		cout << dp[0];
	}
	else
	{
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(dp[i - 1] > dp[i - 1] & a[j])
				{
					dp[i] = dp[i - 1];
					m++;
				}
				else dp[i] =dp[i - 1] & a[j];
			}
		}
		cout << dp[m];
	}
	return 0;
}
