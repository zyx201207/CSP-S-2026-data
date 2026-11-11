#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
vector<int> g[MAX];
int f[MAX];
inline solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(f, 0, sizeof(f));
	queue<int> q;
	q.push(1);
	int st = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v: g[u]){
			if(!f[v]) q.push(v), f[v] = true;
		}
		if(q.empty()) st = u;
	}
	memset(f, 0, sizeof(f));
	queue<pair<int, int>> qq;
	qq.push({st, 0});
	int ee = 0;
	while(!qq.empty()){
		int u = qq.front().first;
		int w = qq.front().second;
		qq.pop();
		for(int v: g[u]){
			if(!f[v]){
				qq.push({v, w + 1});
				f[v] = true;
			}
		}
		ee = w;
	}
	cout << ceil(ee / (k + 1.0)) << '\n';
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
