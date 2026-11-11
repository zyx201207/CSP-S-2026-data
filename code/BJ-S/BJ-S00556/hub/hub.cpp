#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN = 2e6 + 5, INF = 1e9;

int C, T, n, K, u, v, sp, rt;
int fa[MAXN], f[1005][1005], g[1005], d[1005], siz[1005], w[1005], vis[1005], dis[1005][1005];
vector<int> G[MAXN];

void dfs(int u, int father){
	fa[u] = father;
	for (int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if (v == father) continue;
		dfs(v, u);
	}
}

void pre(int u, int fa, int w){
	dis[rt][u] = w;
	for (int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if (v == fa) continue;
		pre(v, u, w + 1);
	}
}

void dp(int u, int fa){
	int leaf = 1; vis[u] = 1; int s = 1; d[u] = 0, siz[u] = 1;
	for (int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if (v == fa || v == sp) continue; 
		dp(v, u), leaf = 0, d[u] = max(d[u], d[v] + 1);
		s += siz[v];
	}
	if (leaf == 1){ f[u][0] = INF, f[u][1] = 0; siz[u] = 1, d[u] = 0; return; }
	for (int i=0; i<=s; i++) f[u][i] = INF;
	f[u][0] = INF, f[u][1] = d[u]; siz[u] = 1;
	for (int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if (v == fa || v == sp) continue;
		for (int j=1; j<=siz[u]; j++) g[j] = f[u][j], f[u][j] = INF;
		for (int j=1; j<=siz[u]; j++){
			f[u][j] = min(f[u][j], max(g[j], d[v] + 1));
			for (int k=1; k<=siz[v]; k++){
				f[u][j + k] = min(f[u][j + k], max(g[j], f[v][k]));
			}
		} siz[u] += siz[v];
	}
}

void clr(){
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1; i<=n; i++) fa[i] = g[i] = d[i] = siz[i] = w[i] = vis[i] = 0;
	for (int i=1; i<=n; i++) for (int j=0; j<=n; j++) f[i][j] = dis[i][j] = 0;
	sp = 0, rt = 0;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> C >> T;
	while (T--){
		cin >> n >> K; int ans = INF; clr();
		for (int i=1; i<n; i++){
			cin >> u >> v;
			G[u].pb(v), G[v].pb(u);
		}
		for (int i=1; i<=n; i++){
			rt = i, dis[rt][i] = 0;
			pre(i, 0, 0);
		}
		for (int i=1; i<=n; i++){
			dfs(i, 0);
			for (int j=1; j<=n; j++){
				if (i == j) continue;
				for (int k=1; k<=n; k++) vis[k] = 0; 
				sp = fa[j], dp(j, 0); int res = 0;
				for (int k=0; k<=n; k++){
					if (k <= siz[j]) w[k] = f[j][k];
					else w[k] = INF;
					//cerr << w[k] << " ";
				} //cerr << "\n";
				if (sp == i) sp = j;
				while (fa[sp] != i) sp = fa[sp]; dp(i, 0);
				for (int k=1; k<=n; k++){
					if (vis[k]) continue;
					res = max(res, min(dis[i][k], dis[j][k]));
				}
				int t = INF;
				for (int k=1; k<min(siz[i]+1, K); k++) t = min(t, max(f[i][k], w[K - k]));
				res = max(res, t);
				ans = min(ans, res);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}