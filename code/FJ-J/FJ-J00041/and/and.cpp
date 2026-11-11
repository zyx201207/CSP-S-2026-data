#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200005] = {0};
	int dp[200005] = {0};
	if(m == 1)
	{
		int ans = -1;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
			ans = max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	else if(m == n)
	{
		int ans = 0;
		cin >> a[1];
		for(int i = 2;i<=n;i++)
		{
			cin >> a[i];
			ans += a[i] & a[i-1];
		}
		cout << ans;
		return 0;
	}
	else if(m == n-1)
	{
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		int ans = 0;
		for(int i = n;i>= 2;i++)
		{
			ans += a[i] & a[i-1];
		}
		cout << ans;
		return 0;
	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		dp[1] = a[n];
		for(int i = 2;i<=m;i++)
		{
			dp[i] = dp[i-1] & a[n-i+1]; 
		}
		cout << dp[m];
	}
	return 0;
}
