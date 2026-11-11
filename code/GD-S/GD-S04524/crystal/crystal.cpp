#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long a[N],b[N],suma[N];//b[N]i补齐到i+1所需;  dp[N]补齐到i高度 1-i所需 
int ans=0;
long long dp[N][N];
int n,m;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		suma[i]=suma[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
		dp[i+1][1]+=dp[i][1]+b[i]*i;//可以优化 
		if(dp[i+1][1]<=m) ans=max(ans,i+1);
		else continue;
	}
	for(int j=2;j<n;j++)//j to i
	{
		for(int i=j+1;i<=n;i++)
		{
			dp[i][j]=dp[i-1][j]+b[i-1]*(i-j);
			if(dp[i][j]<=m) ans=max(ans,i-j+1);
			else continue;
		}
	}
	cout<<ans;
	return 0;
 } 
