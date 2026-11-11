#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=500010,N=505,D=21,INF=1e18;
int c,n,m,d,q,w[M],k,x,y,sz[M],dis[N][N],ans;
struct nd{int x,k;}v[M][D];
void add(int x,int y,int t)
{
	v[x][++sz[x]]=(nd){y,t};
}
void ckmn(int x,int y,int k)
{
	if(dis[x][y]>k)dis[x][y]=dis[y][x]=k;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j)cin>>x>>y,add(x,i,y); 
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=INF;
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i)
		for(int px=2;px<=sz[i];++px)
			for(int py=1;py<px;++py)
				ckmn(v[i][px].x,v[i][py].x,v[i][px].k+v[i][py].k);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			if(dis[i][k]!=INF)
				for(int j=1;j<=n;++j)
					if(dis[k][j]!=INF)
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		cin>>x>>y;
		ans=INF;
		for(int i=1;i<=sz[x];++i)
			for(int j=1;j<=sz[y];++j)
				ans=min(ans,v[x][i].k+v[y][j].k+dis[v[x][i].x][v[y][j].x]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
