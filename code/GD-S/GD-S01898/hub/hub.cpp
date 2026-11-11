#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ": " << (x) << "\n"
#define ll long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;
vector<int> g[1000007], h[1000007];
int dep1[1000007], dep2[1000007], dp[1000007];
void dfs1(int u, int fa){
	dep1[u] = dep1[fa] + 1;
	for(auto v : g[u]) if(v != fa) dfs1(v, u);
}
void dfs2(int u, int fa){
	dep2[u] = dep2[fa] + 1;
	for(auto v : g[u]) if(v != fa) dfs2(v, u);
}
vector<int> stk;
void dfs3(int u, int fa, int V){
//	debug(u);
//	debug(g[u].size());
	if(stk.size() && stk.back() == V) return;
	stk.pb(u);
	for(auto v : g[u]) if(v != fa) dfs3(v, u, V); 
	if(stk.size() && stk.back() == V) return;
	stk.pop_back();
}
void dfs4(int u, int fa){
	dp[u] = 1;
	for(auto v : g[u]) if(v != fa)
		dfs4(v, u), dp[u] = max(dp[u], dp[v] + 1);
}
// g 是当前要做的树，点重新标号，返回f，必须 O(n log n)
vector<vector<int>> work(int n){
	if(n == 1) return {{1}};
	dfs1(1, 0);
	int U = 1, V = 1;
	for(int i = 1; i <= n; i++) if(dep1[i] > dep1[U]) U = i;
	dfs2(U, 0);
	for(int i = 1; i <= n; i++) if(dep2[i] > dep2[V]) V = i;
	stk.clear();
//	debug(U), debug(V);
	dfs3(U, 0, V);
	vector<int> v1, v2;
	if(stk.size() % 2){
		int pt = stk[stk.size() / 2];
		dfs4(pt, 0);
		for(int i = 1; i <= n; i++) v1.pb(dp[i]);
		return {v1};
	}else{
//		debug(stk.size());
		int pt1 = stk[stk.size() / 2 - 1], pt2 = stk[stk.size() / 2];
		dfs4(pt1, 0);
		for(int i = 1; i <= n; i++) v1.pb(dp[i]);
		dfs4(pt2, 0);
		for(int i = 1; i <= n; i++) v2.pb(dp[i]);
		return {v1, v2};
	}
}
int n, k;
pii e[1000007];
bool vis[1000007];
void dfsc(int u, int fa, pii fb){
	vis[u] = 1;
	for(auto v : h[u]) if(v != fa && (u != fb.fi || v != fb.se)
		&& (u != fb.se || v != fb.fi)) dfsc(v, u, fb);
}
void solven2(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) h[i].clear(), g[i].clear();
	if(n <= k){
		cout << "0\n";
		return;
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[i] = {u, v};
		h[u].pb(v);
		h[v].pb(u);
		g[u].pb(v);
		g[v].pb(u);
	}
	auto f1 = work(n);
	int ans = 0x3f3f3f3f;
	for(auto vec : f1){
		sort(vec.begin(), vec.end(), greater<int>());
//		for(auto it : vec) cout << it << " ";
//		cout << "\n";
		ans = min(ans, vec[k]);
	}
	for(int j = 1; j < n; j++){
		for(int i = 1; i <= n; i++) vis[i] = 0;
		dfsc(1, 0, e[j]);
		auto gao = [&]() -> int{
			int s1 = 0;
			vector<int> id(n + 1);
			for(int i = 1; i <= n; i++) if(vis[i]) id[i] = ++s1;
//			debug(s1);
			for(int i = 1; i <= s1; i++) g[i].clear();
			for(int i = 1; i < n; i++){
				if(vis[e[i].fi] && vis[e[i].se]){
//					debug(id[e[i].fi]); debug(id[e[i].se]);
					g[id[e[i].fi]].pb(id[e[i].se]);
					g[id[e[i].se]].pb(id[e[i].fi]);
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = !vis[i];
			return s1;
		};
		auto v1 = work(gao());
		auto v2 = work(gao());
		for(auto vc1 : v1)
			for(auto vc2 : v2){
				vector<int> vec;
				for(auto it : vc1) vec.pb(it);
				for(auto it : vc2) vec.pb(it);
				sort(vec.begin(), vec.end(), greater<int>());
				ans = min(ans, vec[k]);
			}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C, T;
	cin >> C >> T;
	while(T--) solven2();
}

