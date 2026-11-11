#include<bits/stdc++.h>
using namespace std;
long long dij[505][505], w[500005];
vector <pair <int, long long>> e[500005], mp[505];
void dijkstra(int s){
	priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> q;
	dij[s][s] = 0ll;
	q.push({0ll, s});
	while(!q.empty()){
		int x = q.top().second, val = q.top().first;
		q.pop();
		if(dij[s][x] != val){
			continue;
		}
		for(auto i : mp[x]){
			if(dij[s][i.first] > dij[s][x] + i.second){
				dij[s][i.first] = dij[s][x] + i.second;
				q.push({dij[s][i.first], i.first});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int casenum, n, m, d, q;
	cin >> casenum >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x;
			long long val;
			cin >> x >> val;
			e[x].push_back({i, val});
		}
	}
	for(int i = 1; i <= m; i++){
		for(auto x : e[i]){
			for(auto y : e[i]){
				if(x.first != y.first){
					mp[x.first].push_back({y.first, x.second + y.second});
				}
			}
		}
	}
	memset(dij, 0x3f, sizeof dij);
	for(int i = 1; i <= n; i++){
		dijkstra(i);
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(auto i : e[x]){
			for(auto j : e[y]){
				ans = min(ans, i.second + j.second + dij[i.first][j.first]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
} 
