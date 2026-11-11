#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],dp[10005][10005];
void floyd()
{
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1,k,u,W;i<=n;i++)
	{
		cin>>k;
		for(int j=1,v,ww;j<=k;j++)
		{
			cin>>v>>ww;
			W+=ww;
			dp[u][v]=W;
			dp[v][u]=W;
			W=ww;
			u=v;
		}
	}
	floyd();
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		cout<<min(dp[x][y],dp[y][x])+w[x]+w[y]<<"\n";
	}
	return 0;
}
