#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=505;
const int MAXM=5e5+5+MAXN;
const int MAXNODE=1e7+5+MAXM; // 开小了 
const int MAXQ=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
typedef pair<ll,int> PAIR;

int c, n, m, d, q, offer;
int nodew[MAXM];
vector<pair<int,int>> ask[MAXM];
ll ans[MAXQ];
ll dis[MAXNODE];
bool vis[MAXNODE];

struct EDGE{
	int v, la, w;
}; EDGE edge[MAXM<<3];
int head[MAXNODE], Ecnt;

void Dijkstra(int s);
void add(int u, int v, int w);

int read();

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(); n=read(); m=read(); d=read(); q=read();
	
	for(int i=1 ; i<=m ; i++){
		nodew[i]=read();
	}
	for(int i=1, k ; i<=n ; i++){
		k=read();
		for(int j=1, a, t, last=-1 ; j<=k ; j++){
			a=read(); t=read();
			add(a,(a-1)*n+m+i,t);
			add((a-1)*n+m+i,a,t);
			if(last!=-1){
				add((last-1)*n+m+i,(a-1)*n+m+i,0);
				add((a-1)*n+m+i,(last-1)*n+m+i,0);
			}
			last=a;
		}
	}
	
	for(int i=1, x, y ; i<=q ; i++){
		x=read(); y=read();
		ask[x].push_back({y,i});
	}
	
	for(int x=1 ; x<=m ; x++){
		if(ask[x].size()==0) continue;
		Dijkstra(x);
		for(auto y: ask[x]){
			ans[y.second]=dis[y.first]+nodew[x]+nodew[y.first];
		}
	}
	
	for(int i=1 ; i<=q ; i++){
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}

void Dijkstra(int s){
	int N=n*m+m;
	for(int i=0 ; i<=N ; i++){
		vis[i]=0;
		dis[i]=INF;
	}
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	pq.push({0,s});
	dis[s]=0;
	int u=0, v=0; ll w=0;
	while(!pq.empty()){
		u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u] ; i ; i=edge[i].la){
			v=edge[i].v; w=edge[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	return ;
}

void add(int u, int v, int w){
	edge[++Ecnt]={v,head[u],w};
	head[u]=Ecnt;
	return ;
}

int read(){
	int x=0; char c=getchar();
	while(c<'0' || '9'<c) c=getchar();
	while('0'<=c && c<='9') x=x*10+c-'0', c=getchar();
	return x;
}

/*
站厅1 -- 站台1 -- 站台1' -- 站厅2 -- 站台3 
*/
