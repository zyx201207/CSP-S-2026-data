#include<bits/stdc++.h>
#define int long long
#define getswid(x) (m+x)
using namespace std;
int c, n, m, d, q;
vector<int> w;
const int MAXN=510, MAXM=5e5+10;
unordered_map<int, vector<int>> disrem;
vector<pair<int, int>> graph[MAXN+MAXM];
bool vis[MAXN+MAXM];
inline int dist(int x, int y){
	if(disrem.count(x))return disrem[x][y];
	if(disrem.count(y))return disrem[y][x];
	vector<int> dis(n+m+3, 0x7fffffffffffffff);
	memset(vis, 0, sizeof vis);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[x]=0;
	pq.emplace(0, x);
	while(!pq.empty()){
		pair<int, int> now=pq.top();
		int u=now.second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto&e:graph[u]){
			int v=e.first, w=e.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.emplace(dis[v], v);
			}
		}
	}
	disrem[x]=dis;
	return dis[y];
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		int u=getswid(i);
		for(int i=0; i<k; i++){
			int v, w;
			cin>>v>>w;
			graph[u].emplace_back(v, w);
			graph[v].emplace_back(u, w);
		}
	}
	//for(int i=1; i<=n+m; i++){
	//	cout<<i<<": ";
	//	for(auto&e:graph[i]){
	//		cout<<"{"<<e.first<<","<<e.second<<"}, ";
	//	}
	//	cout<<endl;
	//}
	while(q--){
		int x, y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dist(x, y)<<endl;
	}
	return 0;
}
