#include<bits/stdc++.h>
using namespace std;
const int N=1e6+510;
int c,n,m,D,Q;
struct edge{
	int v,w;
};
vector<edge> g[N];
long long d[N];
int vis[N],W[N];
priority_queue<pair<int,int> > q;
void dij(int p){
	for(int i=1;i<=n;i++){
		d[i]=INT_MAX;
		vis[i]=0;
	}
	d[p]=0;
	q.push({0,p});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].w,w=g[u][i].w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				printf("%d %d %d %d\n",u,v,d[u],d[v]);
				q.push({-d[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&W[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int a,b;
			scanf("%d%d",&a,&b);
//			g[2*m+i].push_back({a,b});//2m+iÎªÏß 
			g[a].push_back({m+a,b});//m+aÎªÌü 
			g[m+a].push_back({a,b});
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		dij(x);
		if(d[y]==INT_MAX) d[y]=0;
		printf("%d\n",d[y]+W[x]+W[y]);
	}
	return 0;
}
