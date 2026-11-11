#include <bits/stdc++.h>
using namespace std;
int c, T;
const int N = 1e6 + 10;
vector<int> G[N];
int n, k;
int in[N], r[N], rc, ans;
void dfs(int now, int cnt){
	if(cnt > k || now > n) return;
	else if(cnt == k){
		int zc[11] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
		for(int i = 1; i <= k; i++){
			queue<pair<int, int> > q;
			q.push({r[i], 0});
			zc[r[i]] = 0;
			int vis[11] = {0};
			while(!q.empty()){
				auto d = q.front(); q.pop();
				if(vis[d.first]) continue;
				vis[d.first] = 1;
				for(int v : G[d.first]){
					if(vis[v]) continue;
					zc[v] = min(zc[v], d.second + 1);
					q.push({v, d.second + 1});
				}
			}
		}
		int aa = *max_element(zc + 1, zc + n + 1);
		ans = min(ans, aa);
	} 
	dfs(now + 1, cnt);
	r[++rc] = now;
	dfs(now + 1, cnt + 1);
	rc--;
}
void sol(){
	cin >> n >> k;
	rc = 0,ans = n;
	for(int i = 1; i <= n; i++) in[i] = 0, G[i].clear();
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		in[u]++, in[v]++;
	}
	if(k == n){
		cout<<"0\n"; return;
	}
	if(c <= 3){
		dfs(1, 0);
		cout << ans << '\n';
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--) sol();
}
