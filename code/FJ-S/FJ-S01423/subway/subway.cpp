#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const LL INF = 2e18;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, D, Q;
	cin >> c >> n >> m >> D >> Q;
	vector<vector<pair<int,LL> > > G(n+m+2, vector<pair<int,LL> >(0));// tai = ting + m
	vector<LL> w(m+1);
	for(int i = 1; i <= m; i++) cin >> w[i];
	
	for(int i = 1; i <= n; i++){
		int k, a;
		LL t;
		cin >> k;
		while(k--){
			cin >> a >> t;
			G[m+i].push_back(make_pair(a, t));
			G[a].push_back(make_pair(m+i, t));
		}
	}
	
	while(Q--){
		int s, t;
		cin >> s >> t;
		vector<LL> dist(n+m+2, INF);
		priority_queue<pair<LL,int>, vector<pair<LL,int> >, greater<pair<LL,int> > > q;
		q.push(make_pair(0, s));
		dist[s] = 0;
		 
		while(!q.empty()){
		 	LL d = q.top().fi;
			int u = q.top().se;
		 	q.pop();
		 	if(d != dist[u]) continue;
		 	
		 	for(int i = 0; i < (int)G[u].size(); i++){
		 		int v = G[u][i].fi;
		 		LL wgt = G[u][i].se;
		 		if(dist[v] > dist[u] + wgt){
		 			dist[v] = dist[u] + wgt;
		 			q.push(make_pair(dist[v], v));
				}
			}
		}
		
//		for(int i = 1; i <= n+m+1; i++){
//			cout << "i = " << i << ':';
//			for(int j = 0; j < (int)G[i].size(); j++){
//				cout << G[i][j].fi << ' ' << G[i][j].se << "  ";
//			}
//			cout << '\n';
//		}
//		for(int i = 1; i <= n+m+1; i++) cout << dist[i] << ' ';
//		cout << '\n';
		
		cout << dist[t] + w[s] + w[t] << '\n'; 
	}
	
	return 0;
}
