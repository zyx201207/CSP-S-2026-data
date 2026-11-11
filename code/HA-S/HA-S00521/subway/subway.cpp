#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[1005][1005];
int w[1005];
int t[1005][1005];
int g[1005][1005];
int c,n,m,d,q;
int cnt,qq[1005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,10,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		g[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,v;
			cin>>a>>v;
			t[i][a]=v;
			qq[j]=a;
		}
		for(int t1=1;t1<=k;t1++)
		{
			for(int t2=1;t2<=k;t2++)
			{
				int u=qq[t1];
				int v=qq[t2];
				if(u==v)	continue;
				g[u][v]=min(g[u][v],t[i][u]+t[i][v]);
				g[v][u]=min(g[v][u],t[i][u]+t[i][v]);
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+g[x][y]<<endl;
	}
	return 0;
}
