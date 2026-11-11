#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,t;
};
int w[500005];
vector<node> G[500005];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,q,d;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			G[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=j+1;k<G[i].size();k++){
				int u=G[i][j].v,s=G[i][k].v;
				dis[u][s]=dis[s][u]=min(dis[u][s],G[i][j].t+G[i][k].t);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<i<<" "<<j<<" "<<dis[i][j]<<endl; 
		}
	}*/ 
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<G[x].size();i++){
			for(int j=0;j<G[y].size();j++){
				ans=min(ans,dis[G[x][i].v][G[y][j].v]+G[x][i].t+G[y][j].t);
			} 
		}
		printf("%lld\n",ans+w[x]+w[y]);
	} 
	return 0;
}
