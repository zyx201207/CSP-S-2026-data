#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
//#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second 
using namespace std;

const int N = 1e6 + 5;

int n, k, dep[N], f[N];
vector<int> g[N];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	f[u] = fa;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v, u);
	}
}

int dis[30][30];
bool vis[30];

void init(int u, int ds, int st) {
	dis[st][u] = ds;
	vis[u] = 1;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(vis[v]) continue;
		init(v, ds + 1, st);
	}
}

int ans;
bool flag[30];

void col(int u) {
	flag[u] = 1;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(flag[v] || !vis[v]) continue;
		col(v);
	}
}

bool ck() {
	int cnt = 0;
	memset(flag, 0, sizeof(flag));
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) continue;
		if(!flag[i]) {
			cnt++;
			if(cnt > 2) return 0;
			col(i);
		}
	}
	return 1;
}

void dfs2(int x, int cnt) {
//	cout << x << ' ' << n << endl;
	if(x == n + 1) {
//		cout << "debug" << endl;
		if(ck()) {
			int maxn = 0;
			for(int i = 1; i <= n; i++) {
				int minn = 1e9;
				for(int j = 1; j <= n; j++) {
					if(vis[j]) minn = min(minn, dis[i][j]);
				}
				maxn = max(maxn, minn);
			}
			ans = min(ans, maxn);
//			if(k == 3 && maxn == 1) {
//				cout << "debug " << endl;
//				for(int i = 1; i <= n; i++) {
//					if(vis[i]) cout << i << ' ';
//				}
//				cout << endl;
//			}
		}
		return;
	}
	if(cnt + 1 <= k) {
		vis[x] = 1;
		dfs2(x + 1, cnt + 1);
	}
	vis[x] = 0;
	dfs2(x + 1, cnt);
}

struct node {
	int dep, id;
}a[N];

bool flag2[N];

int cnttt;

void dfs3(int u, int r, int ds, int father) {
	flag2[u] = 1;
	cnttt++;
//	cout << ds << ' ' << cnttt << ' ' << n << endl;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v == father || flag2[v] || ds + 1 > r) continue;
//		cout << v << endl;
		dfs3(v, u, ds + 1, u);
	}
}

bool check(int mid) {
	memset(flag2, 0, sizeof(flag2));
	cnttt = 1;
	int x = a[1].id, tmp = f[x];
	while(dep[x] - dep[tmp] < mid && f[tmp] != 0) tmp = f[tmp];
//	cout << tmp << ' ' << mid << endl;
	dfs3(tmp, mid, 0, tmp);
	bool flagg = 1;
	for(int i = 2; i <= n; i++) {
		x = a[i].id;
		if(!flag2[x] && flagg) {
			flagg = 1;
			int tmp = f[x];
			while(dep[x] - dep[tmp] < mid && f[tmp] != 0) tmp = f[tmp];
//			cout << mid << ' ' << i << ' ' << tmp << endl;
			dfs3(tmp, mid, 0, tmp);
		}
	}
//	cout << cnttt << endl;
	if(cnttt == n) return 1;
	return 0;
}

bool cmp(node x, node y) {
	return x.dep > y.dep;
}

signed main() {//15~30pts
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		memset(dis, 0, sizeof(dis));
		cin >> n >> k;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		int maxdep = 0;
		if(k == 2) {
			for(int i = 1; i <= n; i++) {
				a[i] = {dep[i], i};
				maxdep = max(maxdep, dep[i]);
			}
			sort(a + 1, a + n + 1, cmp);
		}
		if(c <= 6 && c >= 1) {
			for(int i = 1; i <= n; i++) {
				memset(vis, 0, sizeof(vis));
				init(i, 0, i);
			}
			ans = 1e9;
			dfs2(1, 0);
			cout << ans << endl;
		}
		else if(k == 2) {
//			cout << "debug " << maxdep << endl;
			int l = 1, r = maxdep, ans = maxdep;
			while(l <= r) {
				int mid = (l + r) >> 1;
//				cout << l << ' ' << r << endl;
				if(check(mid)) {
					ans = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
//			cout << check(189) << endl;
			cout << ans << endl;
		}
	}
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
