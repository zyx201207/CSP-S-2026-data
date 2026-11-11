#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=550,N=2e4+10,INF=0x3f;
int c,n,m,d,q,t[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	int dis[n+m+10][n+m+10];
	memset(dis,INF,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int u=n+i;
		dis[u][u]=0;
		int k;
		cin>>k;
		while(k--)
		{
			int v,w;
			cin>>v>>w;
			dis[u][v]=min(dis[u][v],w);
			dis[v][u]=dis[u][v];
		}
	}
	for(int k=1;k<=n+m;k++)
		for(int u=1;u<=n+m;u++)
			for(int v=1;v<=n+m;v++)
			{
				if(dis[u][v]>dis[u][k]+dis[k][v])
				{
					dis[u][v]=dis[u][k]+dis[k][v];
					dis[v][u]=dis[u][v];
				}
			}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=dis[u][v]+t[u]+t[v];
		cout<<ans<<'\n';
	}
	return 0;
}
