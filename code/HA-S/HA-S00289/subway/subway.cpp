#include<bits/stdc++.h>
using namespace std;
int m,c,n,q,d,dp[505][505],a[505][500000],x,y,k,t,b,e,u[505],w[505];
int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=999999999;
		}
	}
	for(int i=1;i<=n;i++)
	{
		e=1;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			e++;
			u[e]=x;
			a[x][i]=y;
		}
		for(int j=1;j<=k;j++)
		{
			for(int v=1;v<=k;v++)
			{
				dp[u[j]][u[v]]=min(w[u[j]]+w[u[i]]+a[j][i]+a[v][i],dp[u[j]][u[i]]);
				dp[u[v]][u[j]]=min(w[u[j]]+w[u[i]]+a[j][i]+a[v][i],dp[u[i]][u[j]]);
			}
		}
	}
	

	for(int i=1;i<=q;i++)
	{
		cin>>t>>b;
		for(int j=1;j<=n;j++)
		{
			for(int v=1;v<=n;v++)
			{
				for(int r=1;r<=n;r++)
				{
			//		if(dp[j][v]!=999999999&&dp[v][r]!=999999999)
			//		{
								
						dp[j][v]=min(dp[j][v],dp[j][r]+dp[r][v]-w[r]);
						dp[v][j]=min(dp[v][j],dp[j][r]+dp[r][v]-w[r]);
								
				//	}
				} 
			}
		}
		
		cout<<dp[t][b]<<" ";
	}
	return 0;
}
