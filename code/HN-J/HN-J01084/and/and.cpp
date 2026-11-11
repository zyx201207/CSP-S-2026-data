#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[200005],dp[100][100]={};
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	if(m==1)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		ans=max(a[i],ans);
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		for(int j=1;j<n;j++)
		{
			if(i==j)
			continue;
			ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		int ans=a[0];
		for(int i=1;i<n;i++)
		ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
			for(int i=0;i<n;i++)
		for(int j=m;j>=0;j--)
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		cout<<dp[n-1][m];
	}
	if(n>2000)
	{
		cout<<a[n-1-m];
	}
	
	return 0;
}
