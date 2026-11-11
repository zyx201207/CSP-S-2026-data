#include<bits/stdc++.h>
#define int long long
#define N 200005
#define dbg(x) cerr<<#x<<" "<<x<<endl
using namespace std;
int tid, T, n, k, ans;
vector<int> g[N];
bool vis[N];
vector<int> vc;
int fa[N], dis[35][35];
struct Edge{
	int u, v;
} e[N];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v){
	int fu = find(u), fv = find(v);
	if(fu != fv) fa[fu] = fv;
}
bool check1(){
	for(int i = 1; i <= n - 1; i++){
		int u = e[i].u, v = e[i].v;
		if(vis[u] && vis[v]) merge(u, v);
	}
	set<int> st;
	for(int i = 1; i <= n; i++){
		st.insert(find(i));
	}
	return st.size() == 2; 
}
int cal(){
	int mx = 0;
	for(int i = 1; i <= n; i++){
		int res = 1e18;
		for(int j = 1; j <= n; j++){
			if(vis[j]){
				res = min(res, dis[i][j]);
			}
		}
		mx = max(res, mx);
	}
	return mx;
}
void dfs1(int u, int st, int D, int Fa){
	if(vis[u]) return ;
	dis[st][u] = D;
	vis[u] = 1;
	for(auto v : g[u]){
		if(v == Fa) continue;
		dfs1(v, st, D + 1, u);
	}return ;
}
void dfs(int pos, int cnt){
	if(cnt > k) return ;
	if(pos == n + 1){
		if(cnt != k) return ;
		vc.clear();
		for(int i = 1; i <= n; i++) if(vis[i]) vc.push_back(i);
		for(int i = 1; i <= n; i++) fa[i] = i;
		if(!check1()) return ;
		ans = min(ans, cal());
		return;
	}
	vis[pos] = 1;
	dfs(pos + 1, cnt + 1);
	vis[pos] = 0;
	dfs(pos + 1, cnt);
}
void sml(){
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) vis[j] = 0;
		dfs1(i, i, 0, 0);
	}
	ans = 1e18;
	dfs(1, 0);
	cout << ans << endl;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out","w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> tid >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			e[i] = {u, v};
		}
		if(tid <= 5) sml();
	}
	return 0;
}

