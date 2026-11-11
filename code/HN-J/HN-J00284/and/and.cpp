#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005];
int dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d ",&a[i]);
		maxn = max(maxn,a[i]);
	}

	if(m == 1)
	{
		cout<<maxn;
		return 0;
	}
	if(m == n)
	{
		maxn = a[1];
		for(int i = 2;i <= n;i ++)
			maxn = maxn & a[i];
		cout<<maxn;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1;i <= n;i ++)
			for(int j = i + 1;j <= n;j ++)
				maxn = max(maxn,a[i] & a[j]);
		cout<<maxn;
		return 0;
	}
	
	dp[1] = a[1];
	for(int i = 2;i <= n;i ++)
	{
		
		for(int j = min(m,i);j >= 2;j --)
		{
			dp[j] = max(dp[j],a[i] & dp[j - 1]);
	//		cout<<dp[j]<<" ";
		}
		dp[1] = max(dp[1],a[i]);
	}
	
	
	
	cout<<dp[m];
	
	//	cout<<dp[m];

			
	return 0;
}

