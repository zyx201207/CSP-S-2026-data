#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int N = 110;
int c, t, n, k, u, v, fa[N], dis[N][N], d[N], ans;
vector<int> g[N]; bool s[N]; set<int> st;

void dfs(int u, int f, int rt, int d){
	dis[rt][u] = d;
	for(int v: g[u]){
		if(v == f) continue;
		dfs(v, u, rt, d+1);
	}
}

int fr(int u){
	if(u == fa[u]) return u;
	return fa[u] = fr(fa[u]);
}

void mg(int u, int v){
	u = fr(u), v = fr(v);
	fa[u] = v;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k; ans = 1e9;
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		for(int i = 1; i <= n; i++){
			dfs(i, 0, i, 0);
		}
		for(int i = 0; i < (1 << n); i++){
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				fa[j] = j;
				if(i & (1 << (j-1))) s[j] = 1, cnt++;
				else s[j] = 0;
			}
			if(cnt > k) continue;
			for(int u = 1; u <= n; u++){
				for(int v: g[u]){
					if(s[u] && s[v]) mg(u, v);
				}
			}
			st.clear();
			for(int j = 1; j <= n; j++){
				if(s[j]) st.insert(fr(j));
			}
			if(st.size() > 2) continue;
			int mx = 0;
			for(int u = 1; u <= n; u++){
				d[u] = 1e9;
				for(int v = 1; v <= n; v++){
					if(s[v]) d[u] = min(d[u], dis[u][v]);
				}
				mx = max(mx, d[u]);
			}
			ans = min(ans, mx);
		}
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}
