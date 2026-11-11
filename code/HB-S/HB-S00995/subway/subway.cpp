#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,D=25;
long long dis[N][N],w[M],len[M];
pair<int,int>e[M][D];int id,d,n,m,q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&id,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) {
		int k;scanf("%d",&k);
		for(int u,t;k--;) {
			scanf("%d %d",&u,&t);
			e[u][++len[u]]=make_pair(i,t);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0ll;
	for(int u=1;u<=m;u++) {
		for(int i=1;i<=len[u];i++)
			for(int j=i+1;j<=len[u];j++) {
				int x=e[u][i].first,y=e[u][j].first;
				long long tim=e[u][i].second+e[u][j].second;
				dis[x][y]=min(dis[x][y],tim);dis[y][x]=min(dis[y][x],tim);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int u,v;q--;) {
		scanf("%d %d",&u,&v);long long ans=1e18;
		for(int i=1;i<=len[u];i++)
			for(int j=1;j<=len[v];j++) {
				int x=e[u][i].first,y=e[v][j].first;
				ans=min(ans,w[u]+e[u][i].second
				+dis[x][y]+e[v][j].second+w[v]);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
