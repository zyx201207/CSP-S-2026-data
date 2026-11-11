#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;

int w[N],dis[510][510];
vector <pair<int,int> > v[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) 
	{
		int k;
		scanf("%lld",&k);
		while(k--)
		{
			int x,y;
			scanf("%lld%lld",&x,&y);
			v[x].push_back({i,y}); 
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) for(auto [x,k1]:v[i]) for(auto [y,k2]:v[i]) if(x!=y) 
	{
		dis[x][y]=min(dis[x][y],k1+k2);
		dis[y][x]=min(dis[y][x],k1+k2);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(auto [i,k1]:v[x]) for(auto [j,k2]:v[y]) ans=min(ans,k1+k2+dis[i][j]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
