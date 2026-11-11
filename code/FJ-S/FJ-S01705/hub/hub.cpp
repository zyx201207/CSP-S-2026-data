#include <iostream>
#include <vector>
#define int long long
using namespace std;
constexpr int N = 2000006;

int c, T, n, k, dep[N], f[N][24];
vector<int> edge[2000006];

void dfs(int u, int fa){
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 1; i <= 22; i++){
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int v : edge[u]){
		if(v != fa) dfs(v, u);
	}
}

inline int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	for (int i = 22; i >= 0; i--){
		if(dep[f[u][i]] >= dep[v]){
			u = f[u][i];
		}
	}
	if(u == v) return u;
	for (int i = 22; i >= 0; i--){
		if(f[u][i] != f[v][i]){
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1, 0);
		int ans = 0;
		for (int i = 0; i <= (1 << n); i++){
			int t = i, cnt = 0;
			while (t){
				if(t & 1) cnt++;
				t >>= 1;
			}
			if(cnt != k) continue;
			for (int j = 1; j <= n; j++){
				for (int k = 1; k <= n; k++){
					if((i >> j & 1) == 0 && (i >> k & 1) == 1){
						int l = lca(j, k);
						ans = max(dep[j] + dep[k] - 2 * dep[l], ans);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
