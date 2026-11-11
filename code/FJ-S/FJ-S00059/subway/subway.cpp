#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int,LL> pii;
const int MAXN=5e5+3;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
int C,N,M,D,Q;
LL W[MAXN],dis[MAXN][3];
vector <pii> g[MAXN],rg[MAXN];
struct node{
	int u;
	LL step;
	int state;
	node(int aa,LL bb,int cc):u(aa),step(bb),state(cc) {}
	bool operator<(const node& other) const{
		return step>other.step;
	}
};
inline LL dijkstra(int S,int E){
	memset(dis,0x3f,sizeof(dis));
	priority_queue <node> q;
	q.emplace(S,0,0);
	dis[S][0]=0;
	while(!q.empty()){
		auto cur=q.top();
		int u=cur.u,state=cur.state;
		LL step=cur.step;
		q.pop();
		if(step>dis[u][state]) continue;
		if(state==0){//在地铁口 
			if(dis[u][1]>dis[u][state]+W[u]){//去站厅 
				dis[u][1]=dis[u][state]+W[u];
				q.emplace(u,dis[u][1],1);
			}
		}else if(state==1){//在站厅 
			for(const auto& edge:rg[u]){
				int v=edge.first,w=edge.second;
				if(dis[v][2]>dis[u][state]+w){
					dis[v][2]=dis[u][state]+w;
					q.emplace(v,dis[v][2],2);
				}
			}
			if(dis[u][0]>dis[u][state]+W[u]){//去地铁口 
				dis[u][0]=dis[u][state]+W[u];
				q.emplace(u,dis[u][0],0);
			}
		}else{//在站台 
			for(const auto& edge:g[u]){
				int v=edge.first,w=edge.second;
				if(v==u) continue;
				if(dis[v][1]>dis[u][state]+w){
					dis[v][1]=dis[u][state]+w;
					q.emplace(v,dis[v][1],1);
				}
			}
		}
	}
	return dis[E][0];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> C >> N >> M >> D >> Q;
	for(int i=1;i<=M;i++) cin >> W[i];
	for(int k,i=1;i<=N;i++){
		cin >> k;
		for(int v,w,j=1;j<=k;j++){
			cin >> v >> w;
			g[i].emplace_back(v,w);
			rg[v].emplace_back(i,w);
		}
	}
	for(int S,E,i=1;i<=Q;i++){
		cin >> S >> E;
		cout << dijkstra(S,E) << '\n';
	}
	return 0;
}
