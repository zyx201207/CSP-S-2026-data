#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[505],w[128000];
int a[505][505],dp[505][505],t[505][505],x[505],y[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        dp[i][j]=15413244;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		    cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=min(a[i][j]+w[j],dp[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<dp[x[i]][y[i]]<<endl;
	}
	return 0;
}
