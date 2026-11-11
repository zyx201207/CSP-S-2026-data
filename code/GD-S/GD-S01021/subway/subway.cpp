#include<bits/stdc++.h>
#define int long long
using namespace std;

int C,n,m,D,Q,a[500005];
int dis[505][505];
struct node{int y,w;};
vector<node> g[500005];

void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int c;cin>>c;
		while(c--)
		{
			int x,t;
			cin>>x>>t;
			g[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto u:g[i])
			for(auto v:g[i])
			{
				int x=u.y,s=u.w;
				int y=v.y,t=v.w;
				dis[x][y]=min(dis[x][y],s+t);
			}
	floyd();
	while(Q--)
	{
		int x,y,minn=2e18;
		cin>>x>>y;
		for(auto u:g[x])
			for(auto v:g[y])
			{
				int x=u.y,s=u.w;
				int y=v.y,t=v.w;
				minn=min(minn,s+t+dis[x][y]);
			}
		cout<<minn+a[x]+a[y]<<'\n';
	}
	return 0;
}
