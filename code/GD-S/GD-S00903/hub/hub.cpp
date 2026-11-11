#include <bits/stdc++.h>
using namespace std;

int c,T;
int n,k,vis[1000005];
vector <int> G[1000005],slc;
pair<int,int> ed[1000005];
int fa[100005][32],f[1000005];
int dep[1000005];

int ws(int zt,int p) {
	return bool((zt >> (p - 1)) & 1);
}

int fd(int x) {
	if (f[x] == x) return x;
	return f[x] = fd(f[x]);
}

void dfs(int u,int pre) {
	dep[u] = dep[pre] + 1;
	fa[u][0] = pre;
	for (int i = 1; i <= 31; i++) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for (int v : G[u]) {
		if (v != pre) dfs(v,u);
	}
}

int lca(int x,int y) {
	if (dep[x] < dep[y]) swap(x,y);
	for (int i = 31; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 31; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	}
	return fa[x][0];
}

int dist(int x,int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x,y)];
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int x,y;
			cin >> x >> y;
			ed[i] = {x,y};
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		if (c <= 3) {
			int res = 1e9;
			for (int zt = 0; zt < (1 << n); zt++) {
				slc.clear();
				int cnt = 0;
				for (int i = 1; i <= n; i++) {
					if (ws(zt,i)) {
						vis[i] = zt;
						cnt++;
						slc.push_back(i);
					}
					f[i] = i;
				}
				if (cnt != k) continue;
				for (int i = 1; i < n; i++) {
					if(vis[ed[i].first] == zt && vis[ed[i].second] == zt) {
						int x = fd(ed[i].first),y = fd(ed[i].second);
						if (x != y) {
							f[x] = y;
							cnt--;
						}
					}
				}
				
				if (cnt != 2) continue;
				int mx = 0;
				for (int i = 1; i <= n; i++) {
					int mi = 1e9;
					for (int u : slc) {
						mi = min(mi,dist(i,u));
					}
					mx = max(mx,mi);
				}
				res = min(res,mx);
			}
			cout << res << "\n";
		}
	}
	return 0;
}


/*
maybe 100 + 100 + 32 + 15 = 247pts
考完直接滚去学mo了TAT

AFOed. OI(2023-2026) uid:723036 

*/
