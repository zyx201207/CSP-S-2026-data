#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define DEBUG(x, y) (cerr << "x" << ":" << x << ' ' << (y))

constexpr int MAXN = 1e6+10, MAXE = 2e6+10, MAXT = 4e6+10, MAXNN = 4e3+10;
struct PR {
	int sz, u;
	bool operator<(const PR &x) const {
		return sz == x.sz ? u < x.u : sz < x.sz;
	}
};
int TC, T;
int n, k;
int tot, head[MAXN], nxt[MAXE], to[MAXE];
int vis[MAXE];
int ans;
int sz[MAXN], rt, MN, dep[MAXN], vn[MAXN];
int ans1[MAXN], ans2[MAXN];
int f[MAXNN][MAXNN], g[MAXN];
vector<int> son[MAXN];
vector<int> pre[MAXN], suf[MAXN];
int dis[MAXN];
int vv[MAXN], vl;
//int mnf;

void adde(int u, int v) {
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot++;
}

void clr() {
	tot = 0;
	vl = 0;
	for (int i = 1; i<=n; i++) {
		head[i] = -1;
		vn[i] = 0;
//		son[x].clear();
//		pre[x].clear();
//		suf[x].clear();
	}
	// 清空 f 
}

//void solve1() {
//	ans = n;
//	for (int i = 0; i<tot; i+=2) {
//		vis[i] = vis[i^1] = 1;
//		int u = to[i], v = to[i^1];
//		for (int j = 1; j<=k; j++)
//			ans1[j] = ans2[j] = n;
////		cerr << "u:" << u << " v:" << v << endl; 
//		get1(u, ans1);
//		get1(v, ans2);
//		for (int j = 1; j<k; j++)
//			ans = min(ans, max(ans1[j], ans2[k-j]));
////		cerr << "-------------" << endl;
//		vis[i] = vis[i^1] = 0;
//	}
//	get1(1, ans1);
//	ans = min(ans, ans1[k]);
//	cout << ans << '\n';
//}
//
//void dfs2(int x, int fa, int *ar) { // 我去忘记换根了！ 
//	sz[x] = 1;
//	g[x] = 0;
//	for (int ei = head[x], v; ~ei; ei = nxt[ei])
//		if (!vis[ei] && (v=to[ei]) != fa) {
//			son[x].push_back(v);
//			dfs2(v, x, ar);
//			sz[x] += sz[v];
//			for (int i = 1; i<=sz[x]+sz[v] && i <= k; i++) {
//				if (i <= sz[x])
//					f[x][i] = max(f[x][i], g[v]+1);
//				for (int j = max(1, i-sz[v]); j<=min(i-1, sz[x]); j++) {
//					f[x][i] = min(f[x][i], max(f[x][j], f[v][i-j]));
//				}
//			}
//			g[x] = max(g[x], g[v]+1);
//		}	
////	cerr << "x:" << x << endl;
////	for (int i = 1; i<=k && i <=sz[x]; i++) {
////		cerr << " i:" << i << " f:" << f[x][i] << endl;
////	}
////	cerr << "---" << endl;
//	pre[x].resize(son[x].size()+1);
//	suf[x].resize(son[x].size()+1);
//	for (int i = 1; i<=sz[x]; i++)
//		ar[i] = min(ar[i], f[x][i]);
//}
//
////void dfs3(int x, int fa) {
////	for (int i = 1; i<(int))
////}

//void solve() {
//	for (int i = 0; i<=n; i++)
//		for (int j = 0; j<=n; j++)
//			f[i][j] = 0;
//	for (int i = 1; i<=n; i++)
//		ans1[i] = n;
//	dfs2(1, 0, ans1);
//	ans = ans1[k];
////	DEBUG(ans, endl);
//	for (int i = 0; i<tot; i+=2) {
//		vis[i] = vis[i^1] = 1;
//		int u = to[i], v = to[i^1];
//		for (int j = 1; j<=k; j++)
//			ans1[j] = ans2[j] = n;
////		cerr << "u:" << u << " v:" << v << endl; 
//		dfs2(u, 0, ans2);
//		dfs2(v, 0, ans2);
//		for (int j = 1; j<k; j++)
//			ans = min(ans, max(ans1[j], ans2[k-j]));
//		vis[i] = vis[i^1] = 0;
//	}
//	cout << ans << '\n';
//}


void ddd(int p, int cnt) {
	if (cnt > k) {
		queue<int> qu;
		for (int i = 1; i<=n; i++) {
			if (vn[i]) {
				dis[i] = 0;
				qu.push(i);
			} else dis[i] = -1;
		}
		int mx = 0;
		while (!qu.empty()) {
			int u = qu.front(); qu.pop();
			mx = max(mx, dis[u]);
			for (int ei = head[u], v; ~ei; ei = nxt[ei])
				if (dis[v=to[ei]] == -1) {
					dis[v] = dis[u] + 1;
					qu.push(v);
				}
		}
		ans = min(ans, mx);
		return;
	}
	if (p > n) return;
	for (int i = p; i<=n; i++) {
		vn[i] = 1;
		ddd(i+1, cnt+1);
		vn[i] = 0;
	}
}

void solve3() {
	ans = n;
	ddd(1, 1);
	cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//	freopen("hub2.in", "r", stdin);
//	freopen("myout.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> TC >> T;
	while (T--) {
		cin >> n >> k;
		clr();
		for (int i = 1, u, v; i<n; i++) {
			cin >> u >> v;
			adde(u, v); adde(v, u);
		}
//		if (TC >= 7) {
//			solve1();
//		} else 
//		solve();
		solve3();
	}
	return 0;
}

