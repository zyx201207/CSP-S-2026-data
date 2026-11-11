#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q;
int dis[510][510];
int w[N],k[N];
vector<pair<int,int> > t[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		dis[i][i]=0;
		for(int j=1;j<=k[i];j++)
		{
			int x,w;
			cin>>x>>w;
			t[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto cur:t[i])
		{
			int y=cur.first,w=cur.second;
			for(auto cus:t[i])
			{
				int z=cus.first,v=cus.second;
				if(z==y) continue;
				dis[y][z]=min(dis[y][z],w+v);
				dis[z][y]=min(dis[z][y],w+v);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=LLONG_MAX;
		for(auto cx:t[x])
		{
			int i=cx.first,xw=cx.second;
			for(auto cy:t[y])
			{
				int j=cy.first,yw=cy.second;
				ans=min(ans,xw+yw+w[x]+w[y]+dis[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

