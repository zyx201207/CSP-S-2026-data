#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e5 + 10;

int n, m, a[N];
int fa[N], nxt[N], sz[N], cnt[N], ans[N];
vector<int> g[N];

void dfs(int u) {
	sz[u] = 1;
	cnt[a[u]] ++;
	for(int v : g[u]) {
		dfs(v);
		sz[u] += sz[v];
	}
	if(cnt[a[u]]-- == 1) ans[a[u]] += sz[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fileIO("card");
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for(int i = n; i >= 1; i --) {
		if(!nxt[a[i]]) fa[i] = i + 1;
		else fa[i] = fa[nxt[a[i]]];
		nxt[a[i]] = i;
		g[fa[i]].push_back(i);
	}
	
	for(int i : g[n + 1]) dfs(i);
	
	for(int i = 1; i <= m; i ++) 
		cout << ans[i] << " \n"[i == m];
} 
