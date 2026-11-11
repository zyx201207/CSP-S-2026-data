#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> dij(int s, vector<vector<pair<int, int>>>& adj, int n) {
	priority_queue<pair<int, int>> pq;
	vector<int> dis(n + 1, 4e18);
	vector<bool> vis(n + 1, false);
	dis[s] = 0;
	pq.push({0, s});
	
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		for(auto v : adj[u]) {
			if(dis[v.first] > dis[u] + v.second) {
				dis[v.first] = dis[u] + v.second;
				if(!vis[v.first]) pq.push({dis[v.first], v.first}); 
			}
		}
	}
	return dis;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	vector<vector<pair<int, int>>> adj(m + 1, vector<pair<int, int>>(0));
	for(int i = 1; i <= m; i++) cin >> w[i];
//	cout << "RE\n";
	
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<pair<int, int>> tmp(k + 1, {0, 0});
		for(int j = 1; j <= k; j++) {
//			cout << "RE\n";
			cin >> tmp[j].first >> tmp[j].second;
//			cout << tmp[j].first << ' ' << tmp[j].second << '\n';
		}
		for(int j = 1; j <= k; j++) {
			for(int l = j + 1; l <= k; l++) {
				int value = tmp[j].second + tmp[l].second;
//				if(j == 1 || l == 1) {
//					cout << "test ";
//					cout << j << ' ' << l << ' ' << i << ' ' << value << '\n';
//				}
				adj[tmp[j].first].push_back({tmp[l].first, value});
				adj[tmp[l].first].push_back({tmp[j].first, value});
			}
		}
	}
//	cout << "RE\n";
	
//	for(auto f : adj[1]) {
//		cout << f.first << ' ' << f.second << '\n';
//	}
	
	vector<vector<int>> ans(m + 1, vector<int>(m + 1, 0));
	for(int i = 1; i <= m; i++) {
		vector<int> dis = dij(i, adj, m);
		for(int j = 1; j <= m; j++) {
			ans[i][j] = dis[j];
//			cout << dis[j] << ' ';
		}
//		cout << '\n';
	}
	
	while(q--) {
		int s, t;
		cin >> s >> t;
		cout << w[s] + w[t] + ans[s][t] << '\n';
	}
	
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
