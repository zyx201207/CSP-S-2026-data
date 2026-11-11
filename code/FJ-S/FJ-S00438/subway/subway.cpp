#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<int,int>> pii;

const int MAXM=5e5+5,MAXD=22,MAXN=505;

struct edge{
	int v1,v2;
	ll w;
};

int c,n,m,d,q;

vector<edge> G[MAXM+MAXN][MAXD];
ll dis[MAXM+MAXN][MAXD];
int id[MAXM+MAXN];
ll add[MAXM];

void add_edge(int u1,int u2,int v1,int v2,int w){
	G[u1][u2].push_back({v1,v2,w});
	G[v1][v2].push_back({u1,u2,w});
}

void dijkstra(int s1,int s2){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pii,vector<pii>,greater<pii>> heap;
	dis[s1][s2]=0;
	heap.push({0,{s1,s2}});
	while (heap.size()){
		pii cur=heap.top();
		heap.pop();
		int u1=cur.second.first,u2=cur.second.second;
		for (edge nxt:G[u1][u2]){
			int v1=nxt.v1,v2=nxt.v2;
			ll w=nxt.w;
			if (dis[u1][u2]+w<dis[v1][v2]){
				dis[v1][v2]=dis[u1][u2]+w;
				heap.push({dis[v1][v2],{v1,v2}});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>add[i];
	for (int i=1,p;i<=n;i++){
		cin>>p;
		for (int j=2,u,w;j<=p+1;j++){
			cin>>u>>w;
			id[u]++;
			add_edge(u,id[u],u,0,w);
			add_edge(u,id[u],m+i,0,0);
		}
	}
	for (int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		dijkstra(u,0);
		cout<<dis[v][0]+add[u]+add[v]<<"\n";
	}
	return 0;
}


