#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],dp[20001][20001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=a[i];
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		for(long long j=2;j<=min(i,m);j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;	
} 
