#include<bits/stdc++.h>
using namespace std;
const int N=7e3+10,M=1e6+10;
typedef long long ll;
int c,n,m,d,q;
ll val[N];
ll id[N][2];
ll cnt;
int fst[N],to[M],nxt[M],tot;
ll wgh[M],dis[N][N];
bool vis[N];
struct node2{
	ll u,dis;
	friend bool operator<(node2 a,node2 b){
		return a.dis>b.dis;
	}
};
void dijkstra(int x){
	priority_queue<node2> q;
	for(int i=1;i<=cnt;i++){
		vis[i]=0;
		dis[x][i]=1e18;
	}
	q.push({x,0});
	dis[x][x]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=fst[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[x][u]+wgh[i]<dis[x][v]){
				dis[x][v]=dis[x][u]+wgh[i];
				q.push({v,dis[x][v]});
			} 
		}
	}
}
void add(int u,int v,ll w){
	nxt[++tot]=fst[u];
	to[tot]=v;
	wgh[tot]=w;
	fst[u]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&val[i]);
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		id[i][0]=++cnt;
		id[i][1]=++cnt;
		add(id[i][0],id[i][1],0);
		add(id[i][1],id[i][0],0);
		for(int j=1;j<=k;j++){
			ll v,t;
			scanf("%lld%lld",&v,&t);
			add(v,id[i][0],t),add(id[i][1],v,t);
		}
	}	
	for(int i=1;i<=cnt;i++){
		dijkstra(i);
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",val[u]+dis[u][v]+val[v]);
	}
	return 0; 
}
