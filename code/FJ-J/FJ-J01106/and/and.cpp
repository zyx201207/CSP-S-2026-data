#include<iostream>
#include<cstdio>
using namespace std;
int dp[10086][2086];
int a[200861];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int u=1;u<=n;u++)
	cin>>a[u],dp[u][1]=a[u];
	for(int u=1;u<=n;u++)
	{
		for(int p=2;p<=min(u,m);p++)
		{
			for(int i=1;i<u;i++)
			dp[u][p]=max(dp[u][p],dp[i][p-1]&a[u]);
		}
	}
	for(int u=1;u<=n;u++)
	ans=max(ans,dp[u][m]);
	cout<<ans<<endl;
	return 0;
}
