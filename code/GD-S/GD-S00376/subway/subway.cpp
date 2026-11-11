#include<bits/stdc++.h>
using namespace std;
int ans,n,m,c,d,q,k[505],m[500005],a[505],t[505],dp[505][505];
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>m[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i][j]);
		}
	
	return 0;
}
