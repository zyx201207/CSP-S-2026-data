#include <bits/stdc++.h>
using namespace std;
const long long INF=LLONG_MAX/4; 
long long c , m , n , d , Q; 
long long S[505];
struct Edge{
	int v;
	long long w;
};
vector<Edge> G[500505];
long long dist[505][30505];
struct node{
	int u;
	long long W;
	bool operator<(const node &other)const{
		return W>other.W;
	} 
};
priority_queue<node> q;
void dijkstra(int s){
	for(int i=1;i<=n+m;i++){
		dist[s][i]=INF;
	}
	dist[s][s]=0;
	q.push({s,dist[s][s]});
	while(!q.empty()){
		int u=q.top().u;
		long long W=q.top().W;
		q.pop();
		if(W!=dist[s][u]){
			continue;
		}
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v;
			long long w=G[u][i].w;
			if(dist[s][u]+w<dist[s][v]){
				dist[s][v]=dist[s][u]+w;
				q.push({v,dist[s][v]});
			}
		}
	}
	return ;
}
long long Dist[500505];
void Dijkstra(int s){
	for(int i=1;i<=n+m;i++){
		Dist[i]=INF;
	}
	Dist[s]=0;
	q.push({s,Dist[s]});
	while(!q.empty()){
		int u=q.top().u;
		long long W=q.top().W;
		q.pop();
		if(W!=Dist[u]){
			continue;
		}
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v;
			long long w=G[u][i].w;
			if(Dist[u]+w<Dist[v]){
				Dist[v]=Dist[u]+w;
				q.push({v,Dist[v]}); 
			}
		}
	}	
	return ;
}
void Sub(){
	for(int i=1;i<=Q;i++){
		int u , v;
		cin >>u>>v;
		Dijkstra(u);
		cout <<Dist[u]+S[u]+S[v]<<"\n";
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++){
		cin >>S[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin >>k;
		int u=i+n;
		for(int j=1;j<=k;j++){
			int v;
			long long w;
			cin >>v>>w;
			G[u].push_back({v,w});
			G[v].push_back({u,w}); 
		}
	}
	if((m+n>20000)){ //sigma k<=20000 Q<=2000
		Sub();
		return 0; 
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=Q;i++){
		int u , v;
		cin >>u>>v;
		cout <<dist[u][v]+S[u]+S[v]<<"\n";
	}
	return 0;
} 
