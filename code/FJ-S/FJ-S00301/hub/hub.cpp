#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N  = 1e6 + 100;
int c, T, n, k, tmp, cnt, ans, a[N];
vector<int> g[N];
bool vis[N];
bool check(){
	if(cnt != k) return 0;
	for(int i = 1; i <= n; i++) a[i] = 0;
	tmp = 0;
	
}
void dfs(int x){
	
}
void solve(){
	cnt = 0, ans = 1e9;
	cin >> n >> k; 
	for(int i = 1; i <= n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1);
	cout << ans << "\n";
}
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}

