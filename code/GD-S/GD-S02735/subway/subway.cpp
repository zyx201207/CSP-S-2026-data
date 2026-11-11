#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(n);
	for(auto &v : w) cin >> v;
	vector<vector<pair<int, int>>> t(m);
	for(int i = 0; i < n; i ++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j ++){
			int a, b;
			cin >> a >> b;
			a--;
			t[a].emplace_back(i, b);
		}
	}
	vector<vector<int>> dd(n, vector<int>(n, 1e9));
	for(int i = 0; i < m; i ++){
		for(auto &x : t[i]){
			for(auto &y : t[i]) if(x != y){
				dd[x.first][y.first] = min(x.second + y.second, dd[x.first][y.first]);
			}
		}
	}
	
	while(q --){
		int x, y;
		cin >> x >> y;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> dis(n, 1e9);
//		set<int> ansl;
		for(auto &s : t[x]){
			pq.push({s.second + w[x], s.first});
		}
		while(!pq.empty()){
			int x = pq.top().second, w = pq.top().first;
			pq.pop();
			if(w != dis[x]) continue;
			for(int y = 0; y < n; y ++) if(dis[y] > w + dd[x][y]){
				dis[y] = dd[x][y];
				pq.push({dis[y], y});
			}
		}
		int ans = 1e9;
		for(auto &v : t[y]){
			int e = v.first;
			ans = min(ans, dis[e] + v.second + w[e]);
		}
		cout << ans << '\n';
	}
}
