#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,INF=1e14;
int c,n,m,d,q,w[M],dis[N][N];
vector<pair<int,int>>g[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=INF;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,x,y;j<=k;j++)cin>>x>>y,g[x].push_back({i,y});
	}
	for(int i=1;i<=m;i++)
	{
		for(auto [x,t1]:g[i])for(auto [y,t2]:g[i])if(x!=y)
		{
			dis[x][y]=min(dis[x][y],t1+t2);
			dis[y][x]=min(dis[y][x],t1+t2);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	while(q--)
	{
		int x,y,ans=INF;cin>>x>>y;
		for(auto [xx,t1]:g[x])for(auto [yy,t2]:g[y])ans=min(ans,w[x]+w[y]+dis[xx][yy]+t1+t2);
		cout<<ans<<'\n';
	}
	return 0;
}
