#include<bits/stdc++.h>
using namespace std;
const int N=5e5+505;
typedef long long ll;
int c,d,q,n,m,w[N]; 
ll dis[N];
bool vis[N];
struct edge{
	int v,w;
};
struct node{
	int id;
	long long dist;
	friend bool operator < (node a,node b){
		return a.dist > b.dist; 
	}
};
vector<edge> g[N];
ll dij(int s,int t){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i : g[u]){
			int v=i.v,w=i.w;
			if(!vis[v] && dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d %d",&a,&t);
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		ll ans=dij(x,y)+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//const int N=5e5+5;
//typedef long long ll;
//int c,d,q,n,m,w[N],a[505][N],t[505][N]; 
//bool vis[N];
//struct edge{
//	ll v,w;
//};
//vector<edge> g[N];
//ll gs[505][505],dis[505][505];
//int main(){
////	freopen("subway.in","r",stdin);
////	freopen("subway.out","w",stdout); 
//	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
//	for(int i=1;i<=m;i++){
//		scanf("%d",&w[i]);
//	}
//	for(int i=1;i<=n;i++){
//		int k;
//		scanf("%d",&k);
//		for(int j=1;j<=k;j++){
//			scanf("%d %d",&a[i][j],&t[i][j]);
//			g[a[i][j]].push_back({m+i,t[i][j]});
//		}
//	}
//	memset(gs,0x3f,sizeof(gs));
//	memset(dis,0x3f,sizeof(dis));
//	for(int k=1;k<=m;k++){
//		for(int i=0;i<g[k].size();i++){
//			for(int j=i+1;j<g[k].size();j++){
//				edge a=g[k][i],b=g[k][j];
//				int u=a.v,v=b.v;
//				dis[v][u]=dis[u][v]=gs[u][v]=gs[v][u]=min(gs[u][v],a.w+b.w);
//			}
//		}
//	}
//	for(int i=1;i<=n;i++) dis[i][i]=0;
//	for(int k=1;k<=n;k++){
//		for(int u=1;u<=n;u++){
//			for(int v=u+1;v<=n;v++){
//				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
//			}
//		}
//	}
//	while(q--){
//		int x,y;
//		scanf("%d %d",&x,&y);
//		ll ans=LONG_LONG_MAX;
//		for(auto i : g[x]){
//			for(auto j : g[y]){
//				ll u=i.v,v=j.v;
//				ll sum=dis[u][v]+t[u][x]+t[v][y]+w[x]+w[y];
//				ans=min(ans,sum);
//			}
//		}
//		printf("%lld\n",ans);
//	}
//	return 0;
//}

