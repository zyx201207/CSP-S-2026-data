#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> dis;
vector<int> vis;
vector<vector<int>> r;
struct twice{
	long long first, second;
	bool operator>(const twice other) const{
		if(this -> first == other.first){
			return this -> second > other.second;
		}
		return this -> first > other.first;
	}
};
void djs(int start){
	priority_queue<twice, vector<twice>, greater<twice>> pq;
	pq.push({0, start});
	dis[start][start] = 0;
	while(!pq.empty()){
		twice t = pq.top();
		pq.pop();
		if(!vis[t.second]){
			vis[t.second] = true;
			dis[t.second][start] = t.first;
			dis[start][t.second] = t.first;
			for(int i = 0; i < r[t.second].size(); i ++){
				if(r[t.second][i] != LONG_MAX){
					if(!vis[i]){
						pq.push({dis[t.second][start] + r[t.second][i], i});
					}
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, c, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	r.resize(m + 1, vector<int> (m + 1, LONG_MAX));
	vector<twice> sub;
	for(int i = 0; i < m; i ++){
		cin >> w[i + 1];
	}
	for(int i = 0; i < n; i ++){
		sub.clear();
		int k;
		cin >> k;
		for(int j = 0; j < k; j ++){
			int u, t;
			cin >> u >> t;
			for(int l = 0; l < sub.size(); l ++){
				r[u][sub[l].first] = min(r[u][sub[l].first], sub[l].second + t);
				r[sub[l].first][u] = min(r[sub[l].first][u], sub[l].second + t);
			}
			sub.push_back({u, t});
		}
	}
	dis.resize(m + 1, vector<int> (m + 1, -1));
	for(int i = 1; i <= m; i ++){
		vis.clear();
		vis.resize(m + 1, false);
		djs(i);
	}
	for(int i = 0; i < q; i ++){
		int a, b;
		cin >> a >> b;
		cout << dis[a][b] + w[a] + w[b] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
