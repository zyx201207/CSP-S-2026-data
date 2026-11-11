#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,n,d,q,w[500008],k[510],dis[5010][5010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,t;
			cin>>x>>t;
			dis[i][x]=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i;k<j;k++)
			{
				dis[i][j]=min(dis[i][k],dis[k+1][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<(dis[u][v]+w[u]+w[v]-9)*9;
	}
}


