#include <bits/stdc++.h>
using namespace std;
//vodyanitsa & odette
#define ll long long
struct edge{
	long long w;
	int v;
	edge(long long _w,int _v){
		w=_w;
		v=_v;
	}
};
long long a[510][510]; //matrix of the graph, between the left point
ll b[500010];//entrance to platform
vector<edge> a_raw[500010];//original graph,from the right points
long long dis[510][510];
bool vis[510];
void floyd(int n){
	memset(dis,0x3f,sizeof dis);
	for (int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for (int _=1;_<=n;_++){
			int minpos=0;
			for (int k=1;k<=n;k++){
				if (dis[i][minpos]>dis[i][k] && !vis[k]){
					minpos=k;
				}
			}
			vis[minpos]=1;
			for (int k=1;k<=n;k++){
				dis[i][k]=min(dis[i][k],dis[i][minpos]+a[minpos][k]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for (int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			int v;
			ll w;
			scanf("%d%lld",&v,&w);
			a_raw[v].push_back(edge(w,i));
		}
	}
	memset(a,0x3f,sizeof a);
	for (int i=1;i<=m;i++){
		for (edge e1:a_raw[i]){
			int u=e1.v;
			ll w1=e1.w;
			for (edge e2:a_raw[i]){
				int v=e2.v;
				if (u==v) continue;
				ll w2=e2.w;
				a[u][v]=min(a[u][v],w1+w2);
			}
		}
	}
	floyd(n);
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			printf("%lld ",dis[i][j]);
//		}
//		putchar('\n');
//	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e17;
		for (edge e1:a_raw[x]){
			int u=e1.v;
			long long w1=e1.w;
			for (edge e2:a_raw[y]){
				int v=e2.v;
				ll w2=e2.w;
				ans=min(ans,dis[u][v]+w1+w2);
//				printf("%lld %lld %lld\n", w1,w2,dis[u][v]);
			}
		}
		printf("%lld\n",ans+b[x]+b[y]);
	}
	
	return 0;
}
