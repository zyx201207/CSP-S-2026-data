#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4e4+1000 + 10;

vector<pair<int,int> > g[N];
int c,n,m,d,q;
int k[N];
int dis[505][N];

void Input(){
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		int w;
		cin >> w;
		g[i].push_back({i+m, w});
		g[i+m].push_back({i, w});
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int ai,ti;
			cin >> ai >> ti;
			g[2*m+i].push_back({ai+m, ti});
			g[ai+m].push_back({2*m+i, ti});
		}
	}
}

void Dijkstra(int st){
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	dis[st][m*2+st] = 0;
	pq.push({dis[st][m*2+st], m*2+st});
	while(!pq.empty()){
		int dist=pq.top().first,u=pq.top().second;
		pq.pop();
		if(dist != dis[st][u]) continue;
		for(auto tmp : g[u]){
			int v = tmp.first, w = tmp.second;
			if(dis[st][v] > dis[st][u] + w){
				dis[st][v] = dis[st][u] + w;
				pq.push({dis[st][v], v});
			}
		}
	}
}

void Solve(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		Dijkstra(i);
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		int ans=LONG_LONG_MAX;
		for(int i=1;i<=n;i++){
			ans = min(ans, dis[i][u] + dis[i][v]);
		}
		cout << ans << '\n';
	}
	
}

signed main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	//cin >> T;
	while(T--){
		Input();
		Solve();
	}
	
	return 0;
}
