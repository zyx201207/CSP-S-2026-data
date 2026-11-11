#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1;

int testnum, t, n, k, dep[MAXN], ans = 1e18, fa[MAXN];
vector<int> c[MAXN];
bool vis[MAXN];
vector<int> hub;
struct Edge {
	int x, y;
}eg[MAXN];
int ml = 1e18;
void dfs2(int x, int fa) {
	dep[x] = dep[fa] + 1;
	if(vis[x]) {
		ml = min(ml, dep[x]);
	}
	for(int i = 0; i < (int)c[x].size(); i++) {
		int y = c[x][i];
		if(y == fa) {
			continue;
		}
		dfs2(y, x);
	}
}
int Find(int x) {
	return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}
unordered_set<int> st;
void check() {
	st.clear();
	int maxx = 0;
	iota(fa + 1, fa + n + 1, 1);
	for(int i = 1; i < n; i++) {
		int x = eg[i].x, y = eg[i].y;
		if(vis[x] && vis[y]) {
			x = Find(x);
			y = Find(y);
			if(x != y) {
				fa[y] = x;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			st.insert(Find(i));
		}
	}
	if(st.size() > 2) {
		return;
	}
	for(int i = 1; i <= n; i++) {
		fill(dep + 1, dep + n + 1, 0);
		ml = 1e18;
		dep[0] = -1;
		dfs2(i, 0);
//		cout << ml << " ";
		maxx = max(maxx, ml);
	}
	ans = min(ans, maxx);
	return;
}
void dfs(int x, int ud) {
	if((n - x + 1) + ud < k) {
		return;
	}
	if(x == n + 1) {
		if(ud != k) {
			return;
		}
		check();
		return;
	}
	hub.push_back(x);
	vis[x] = true;
	dfs(x + 1, ud + 1);
	hub.pop_back();
	vis[x] = false;
	dfs(x + 1, ud);
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> testnum >> t;
	while(t--) {
		cin >> n >> k;
		ans = 1e18;
		hub.clear();
		st.clear();
		for(int i = 1; i <= n; i++) {
			c[i].clear();
		}
		for(int i = 1, x, y; i < n; i++) {
			cin >> x >> y;
			eg[i] = {x, y};
			c[x].push_back(y);
			c[y].push_back(x);
		}
		dfs(1, 0);
//		hub.push_back(2);
//		hub.push_back(4);
//		vis[2] = vis[4] = true;
//		check();
		cout << ans << "\n";
	}
	return 0;
} 
