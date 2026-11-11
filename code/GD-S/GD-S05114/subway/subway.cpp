#include <bits/stdc++.h>
using namespace std;
const int N = 505,int INF = 0x3f3f3f3f;
using ll = long long;
int c,n,m,d,q,x,y;
int w[N],t[N][N],tong_pai[N],edge_cnt;
queue<int> q;
struct Edge{
	int v,wz;
	Edge(int _v,int _wz) : v(_v),wz(_wz){}	
};
struct Node{
	int u,dis;
	Node(int _u,int _dis) : u(_u),dis(_dis){}	
	bool operator<(const Node &other)const{
		return dis>other.dis;
	}
};
vector<Edge> adj[N];
bool vis[N];
int dis[N];
int sy_xian(int node){
	int number;
	for(int i = 1;i<=n;i++){
		if(t[i][node]!=0){
			number = i;
			break;
		}
	}
	return number;
}
void dijkstra(int start,int end){
	fill(vis,vis+N,false);
	fill(dis,dis+N,INF);
	dis[start] = 0;
	priority<Node> q;
	q.emplace_back(start,dis[start]);
	while(!q.empty()){
		int u = q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		if(u==end) break;
		for(Edge &e : adj[u]){
			int v = e.v,w = e.w;
			if(!vis[v]){
				int new_dis = dis[u] + w;
				if(new_dis<dis[v]){
					dis[v] = new_dis;
					q.emplace_back(v,dis[v]);
				}
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int bh = 1;bh<=k;bh++){
			int j;
			cin>>j;
			tong_pai[j]++;
			cin>>t[i][j];
		}
	}
	for(int i = 1;i<=m;i++){
		if(tong_pai[i]>1){
			edge_cnt+=(tong_pai[i]-1);
			q.push(i);
		}
	}
	for(int i = 1;i<=edge_cnt;i++){
		int node = q.front();
		int xian[N];
		int cnt = 1;
		q.pop();
		for(int j = 1;j<=n;j++){
			if(t[j][node]!=0){
				xian[cnt] = j;
				cnt++;
			}
			for(int k1 = 1;k1<=cnt,k1++){
				for(int k2 = 1;k2<=cnt,k2++){
					if(k1!=k2){
						adj[k1].emplace_back(k2,t[xian[k1]][node]+t[xian[k2]][node]);
					}
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		dijkstra(x,y);
		cout<<dis[y]+w[x]+w[y]+t[sy_xian[x]][x]+t[sy_xian[y]][y];
	}
	return 0;
}
