#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
vector<int> edge[MAXN];
bool vis[MAXN];
int n;
void dfs1(int u, int msk){
	vis[u] = true;
	for(int v : edge[u]){
		if(vis[v] || !(msk >> v & 1)) continue;
		dfs1(v, msk);
	}
}
int dfs2(int u, int msk){
	vis[u] = true;
	if(msk >> u & 1) return 0;
	int mind = 1e9;
	for(int v : edge[u]){
		if(vis[v]) continue;
		mind = min(mind, dfs2(v, msk));
	}
	return mind + 1;
}
inline bool check(int msk){
	for(int i = 0; i < n; i++) vis[i] = false;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i] && (msk >> i & 1)){
			dfs1(i, msk);
			cnt++;
			if(cnt > 2) return false; 
		}
	}
	return true;
}
inline int calc(int msk){
	int maxn = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) vis[j] = false;
		int num = dfs2(i, msk);
		maxn = max(maxn, num);
	}
	return maxn;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--){
		int k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) edge[i].clear();
		if(c <= 3){
			for(int i = 1; i < n; i++){
				int u, v;
				cin >> u >> v;
				u--, v--;
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
			int ans = 1e9;
			for(int msk = 0; msk < (1 << n); msk++)
				if(__builtin_popcount(msk) == k && check(msk)) ans = min(ans, calc(msk));
			cout << ans << "\n";
		}
	}
	return 0;
}
