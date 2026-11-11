#include <bits/stdc++.h>
using namespace std;
const int L=505;
const int M=5e5+7;
const long long oo=1e15+7;
int visit[M]={0};
int tim[M];
long long dp[L][L]={0};
int a[M][25]={0};
int b[M][25]={0};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>tim[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int u,t;
			cin>>u>>t;
			a[u][++visit[u]]=i;
			b[u][visit[u]]=t;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			dp[i][j]=oo;
		}
	}
	for (int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		int w=visit[i];
		for (int j=1;j<=w;j++)
		{
			for (int k=1;k<=w;k++)
			{
					int x=a[i][j];
					int y=a[i][k];
					int u=b[i][j];
					int v=b[i][k];
					dp[x][y]=min(dp[x][y],1ll*u+v*1ll);
			}
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if(dp[i][k]+dp[k][j]<dp[i][j])
				{
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		int u,v;
		long long ans=oo;
		cin>>u>>v;
		for (int j=1;j<=visit[u];j++)
		{
			for (int k=1;k<=visit[v];k++)
			{
				int x=a[u][j],y=a[v][k];
				int t1=b[u][j],t2=b[v][k];
				ans=min(ans,dp[x][y]+t1+t2);
			}
		}
		 cout<<ans+tim[u]+tim[v]<<endl; 
	}	
	return 0;
}


