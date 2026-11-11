#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 520
#define M 500010
#define K 20010
int dis[N][N];
int w[M],k[N];
map<pair<int,int>,int>a,t;
int aa[N][K],tt[N][K];
int aaa[3][M],ttt[3][M];
struct nd{int l,rt[25];}st[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	if(n<=2)
	{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>aaa[i][j];cin>>ttt[i][aaa[i][j]];
				st[aaa[i][j]].rt[++st[aaa[i][j]].l]=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=(1ll<<60);
				if(i==j)dis[i][j]=0;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int u=1;u<=st[j].l;u++)
			{
				for(int v=1;v<=st[j].l;v++)
				{
					int uu=st[j].rt[u],vv=st[j].rt[v];
					dis[uu][vv]=min(dis[uu][vv],ttt[uu][j]+ttt[vv][j]);
				}
			}
		}
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				for(int w=1;w<=n;w++)
				{
					dis[u][v]=min(dis[u][v],dis[u][w]+dis[w][v]);
				}
			}
		}
		for(int i=1,x,y;i<=q;i++)
		{
			cin>>x>>y;
			int ans=(1ll<<60);
			for(int u=1;u<=st[x].l;u++)
			{
				for(int v=1;v<=st[y].l;v++)
				{
					int uu=st[x].rt[u],vv=st[y].rt[v];
					ans=min(ans,ttt[uu][x]+ttt[vv][y]+dis[uu][vv]);
				}
			}
			printf("%lld\n",ans+w[x]+w[y]);
		}
		return 0;
	}
	if(n<N&&m<K)
	{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>aa[i][j];cin>>tt[i][aa[i][j]];
				st[aa[i][j]].rt[++st[aa[i][j]].l]=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=(1ll<<60);
				if(i==j)dis[i][j]=0;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int u=1;u<=st[j].l;u++)
			{
				for(int v=1;v<=st[j].l;v++)
				{
					int uu=st[j].rt[u],vv=st[j].rt[v];
					dis[uu][vv]=min(dis[uu][vv],tt[uu][j]+tt[vv][j]);
				}
			}
		}
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				for(int w=1;w<=n;w++)
				{
					dis[u][v]=min(dis[u][v],dis[u][w]+dis[w][v]);
				}
			}
		}
		for(int i=1,x,y;i<=q;i++)
		{
			cin>>x>>y;
			int ans=(1ll<<60);
			for(int u=1;u<=st[x].l;u++)
			{
				for(int v=1;v<=st[y].l;v++)
				{
					int uu=st[x].rt[u],vv=st[y].rt[v];
					ans=min(ans,tt[uu][x]+tt[vv][y]+dis[uu][vv]);
				}
			}
			printf("%lld\n",ans+w[x]+w[y]);
		}
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[{i,j}];cin>>t[{i,a[{i,j}]}];
			st[a[{i,j}]].rt[++st[a[{i,j}]].l]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=(1ll<<60);
			if(i==j)dis[i][j]=0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int u=1;u<=st[j].l;u++)
		{
			for(int v=1;v<=st[j].l;v++)
			{
				int uu=st[j].rt[u],vv=st[j].rt[v];
				dis[uu][vv]=min(dis[uu][vv],t[{uu,j}]+t[{vv,j}]);
			}
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(int v=1;v<=n;v++)
		{
			for(int w=1;w<=n;w++)
			{
				dis[u][v]=min(dis[u][v],dis[u][w]+dis[w][v]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		int ans=(1ll<<60);
		for(int u=1;u<=st[x].l;u++)
		{
			for(int v=1;v<=st[y].l;v++)
			{
				int uu=st[x].rt[u],vv=st[y].rt[v];
				ans=min(ans,t[{uu,x}]+t[{vv,y}]+dis[uu][vv]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
