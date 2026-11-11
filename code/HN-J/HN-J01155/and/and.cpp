#include <bits/stdc++.h>
using namespace std;
int n,m,c,ans = -1;
int dp[100005],a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			c = a[i];
			for (int j = i + 1;j <=n;j++)
			{
				c = c & a[j];
				ans = max(ans,c);
				c = a[i];
			}
		}
		cout << ans;
		return 0;	
	}
	if (2 < m)
	{
		dp[2] = a[1] & a[2];
	}
	for (int i = 3;i <= n;i++)
	{
		if (i < m)
		{
			dp[i] = dp[i - 1] & a[i];
		}
		else
		{
			dp[i] = dp[i - m] & a[i];
		}
	}
	cout << dp[n];
	return 0;
} 
