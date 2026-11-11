#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=505;
const int M=5e5+5;
const ll INF=4e18;
int c,n,m,d,q;
ll w[M];

struct Node{
	int v;
	ll w;
	bool operator <(Node a)const{
		return w>a.w;
	}
};
vector<Node> g[M]; // 站厅 i 连接的线路 
vector<Node> adj[N];
ll dis[N][N];

void Dijkstra(int s,ll d[]){
	for(int i=1;i<=n;i++) d[i]=INF;
	d[s]=0ll;
	priority_queue<Node> pq;
	pq.push({s,0ll});
	while(pq.size()){
		Node u=pq.top();
		pq.pop();
		for(Node e:adj[u.v]){
			int v=e.v;
			ll w=e.w;
			if(d[v]>d[u.v]+w){
				d[v]=d[u.v]+w;
				pq.push({v,d[v]});
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i]; // [地铁口 i -> 站厅 i] 的时间 
	
	// 第 i 条线路
	// 不用考虑乘地铁的时间，直接把线路 i 的站台看做线路 i 
	// 换乘：线路 i -> 站厅 v -> 线路 j  
	// t[v][i]+t[v][j]
	// 站厅数量 m（5e5），线路数量 n（500） 
	for(int i=1;i<=n;i++){
		int k; // 线路 i 经过的地铁站数 
		cin >> k;
		for(int j=1;j<=k;j++){
			int a;
			ll t; // [站厅 a -> 线路 i] 的时间 
			cin >> a >> t;
			g[a].push_back({i,t});
		}
	}
	
	/*for(int i=1;i<=m;i++){
		cout << i << ": ";
		for(auto u:g[i]) cout << u.v << " ";
		cout << "\n";
	}
	cout << "\n";*/
	
	for(int a=1;a<=m;a++){
		int len=g[a].size();
		for(int i=0;i<len;i++){
			auto pi=g[a][i];
			for(int j=i+1;j<len;j++){
				auto pj=g[a][j];
				ll dij=pi.w+pj.w;
				adj[pi.v].push_back({pj.v,dij});
				adj[pj.v].push_back({pi.v,dij});
			}
		}
	}
	
	/*for(int i=1;i<=n;i++){
		cout << i << ":\n";
		for(auto v:adj[i]){
			cout << v.v << " " << v.w << "\n";
		}
	}
	cout << "\n";*/
	
	for(int i=1;i<=n;i++){
		Dijkstra(i,dis[i]);
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/
	
	// 把线路看成点，换乘（线路->站厅->线路）看成边 
	// 长度：t[v][i]+t[v][j] 
	
	while(q--){
		int s,t;
		cin >> s >> t;
		
		ll res=INF;
		for(auto gs:g[s]){
			//ll nr=w[s]+w[t];
			int su=gs.v;
			ll du=gs.w;
			//nr+=du; // 站厅 s -> 线路 su 
			//cout << su << ": ";
			for(auto gt:g[t]){
				int sv=gt.v;
				ll dv=gt.w;
				ll nr=w[s]+w[t]+du+dis[su][sv]+dv;
				//nr+=dis[su][sv]; // 换乘线路 su -> 线路 sv 
				//nr+=dv; // 线路 sv -> 站厅 t 
				//cout << sv << " ";
				res=min(res,nr);
			}
			//cout << "\n";
		} 
		
		cout << res << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
