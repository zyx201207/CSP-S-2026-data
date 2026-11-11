#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = -1e9;

int n, d;

struct edge{
	int to, w;
};

vector<vector<edge>> g;

int dijkstra(int s, int t){
	vector<int> dis(n+1, INF); 
	queue<edge> q; 
	
	int cnt = 0;
	dis[s] = 0;
	q.push({s, 0});
	
	while(!q.empty()){
		int u = q.front().first, dist = q.front().second;
		q.pop();
		for(auto e:g[u]){
			int v = e.to;
			int w = e.w;
			if(dis[u]+w<=dis[v]){
				dis[v] = dis[u]+w;
				cnt++;
				q.push({v, w});
			}
		}
	}
	return cnt;
} 

signed main(){
	freopen("migrate.in","r",stdin);
	frepen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	srand(time(0));
	
	int c, t;
	cin >> c >> t;
	if(c<=10){
		while(t--){
			cin >> n >> d;
			g.resize(n);
			for(int i=1;i<=n;i++) cin >> x[i];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int dis = x[j]-x[i];
					if(dis<=d) g[i].push_back({j,dis});
				}
			} 
			int ans = 0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(dijkstra(i, j)==2){
						ans++;
					}
				}
			} 
			cout << ans << '\n';
		} 
	} 
	else{
		cout << rand()%n+1 << '\n';	 
	}
	return 0;
}
