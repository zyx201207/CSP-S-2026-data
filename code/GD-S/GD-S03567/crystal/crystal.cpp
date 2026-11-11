#include<bits/stdc++.h>
using namespace std;
long long maxx=1,n,m,dp[500005],a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		int sum=m; 
		for(int j=1;j<i;j++)
		{
			if(sum>=a[i]-a[j])
			{
				sum=sum-a[i]+a[j];
				dp[i]++;
			} 
	    } 
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	return 0;
}
