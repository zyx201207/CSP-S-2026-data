#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp(x, y) make_pair((x), (y))
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define bk(x) x.back()
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

bool MemST;

char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
void read(int &x) {
	x = 0;
	char ch = gc();
	while (ch < '0' || ch > '9') ch = gc();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
}

const int MAXN = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int ID, n, m;
vector<int> e[MAXN];

namespace SLV1 {
	const int N = 4005;
	
	int D;
	int f[N] = {0};
	pii g[N][2];
	
	void dfs(int x, int pr) {
		f[x] = 1;
		g[x][0] = g[x][1] = mp(0, 0);
		for (auto i: e[x])
			if (i != pr) {
				dfs(i, x);
				f[x] += (g[i][0].fi + 1 > D) * f[i];
				
				pii v = mp(g[i][0].fi + 1, i);
				if (v > g[x][0]) swap(v, g[x][0]);
				if (v > g[x][1]) swap(v, g[x][1]);
			}	
	}	
	int res;
	void srh(int x, int pr, int nf = 0, int ng = 0) {
		int F = f[x] + (ng > D) * nf;
		res = min(res, F);
		for (auto i: e[x])
			if (i != pr) {
				int ff = F - (g[i][0].fi + 1 > D) * f[i];
				int gg = max(ng + 1, (g[x][0].se == i ? g[x][1].fi : g[x][0].fi) + 1);
				srh(i, x, ff, gg);
			}
	}
	
	bool chk(int mid) {
		D = mid;
		for (int i = 1; i <= n; i++)	
			for (auto j: e[i]) {
				if (i < j) {
					int tot = 0;
					res = inf, dfs(i, j), srh(i, j), tot += res;
					if (tot >= m) continue; 
					res = inf, dfs(j, i), srh(j, i), tot += res;
					if (tot <= m) return true;
				}
			}
		return false;
	} 
	
	void slv() {	
		int l = -1, r = n;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (chk(mid)) r = mid;
			else l = mid;
		}
		printf("%d\n", r); 
	}	
}

namespace SLV2 {
	const int N = MAXN;
	
	int D;
	int f[N] = {0};
	pii g[N][2];
	
	void dfs(int x, int pr) {
		f[x] = 1;
		g[x][0] = g[x][1] = mp(0, 0);
		for (auto i: e[x])
			if (i != pr) {
				dfs(i, x);
				f[x] += (g[i][0].fi + 1 > D) * f[i];
				
				pii v = mp(g[i][0].fi + 1, i);
				if (v > g[x][0]) swap(v, g[x][0]);
				if (v > g[x][1]) swap(v, g[x][1]);
			}	
	}	
	int res;
	void srh(int x, int pr, int nf = 0, int ng = 0) {
		int F = f[x] + (ng > D) * nf;
		res = min(res, F);
		for (auto i: e[x])
			if (i != pr) {
				int ff = F - (g[i][0].fi + 1 > D) * f[i];
				int gg = max(ng + 1, g[x][g[x][0].se == i].fi + 1);
				srh(i, x, ff, gg);
			}
	}
	
	vector<pii> ed;
	
	bool chk(int mid) {
		D = mid;
		for (auto it: ed) {
			int u, v;
			tie(u, v) = it;
			int tot = 0;
			res = inf, dfs(u, v), srh(u, v), tot += res;
			if (tot >= m) continue;
			res = inf, dfs(v, u), srh(v, u), tot += res; 
			if (tot <= m) return true;
		}
		return false;
	} 
	
	int B;
	
	struct Node {
		int u, v, w;
		Node (int _u = 0, int _v = 0, int _w = 0) :
			u(_u), v(_v), w(_w) {} 
	};
	bool operator<(Node x, Node y) {
		return x.w < y.w;
	}
	priority_queue<Node> q;
	
	
	void cal(int x, int pr, int ng = 0) {
		if (pr) {
			q.emplace(x, pr, abs((ng - 1) - g[x][0].fi));
			if (sz(q) > B) q.pop();
		}
		for (auto i: e[x])
			if (i != pr) {
				int gg = max(ng + 1, g[x][g[x][0].se == i].fi + 1);
				cal(i, x, gg);
			}
	} 
	
	void init() {
		dfs(1, 0);
		cal(1, 0);
		
		ed.clear();
		while (sz(q)) ed.eb(q.top().u, q.top().v), q.pop();
		reverse(all(ed));
		
	//	printf("res=%d\n", res);
	//	for (auto it: ed) printf("(%d, %d)\n", it.se, it.fi);
	}
	
	void slv() {	
		B = (ID <= 10 ? 1000 : (ID <= 14 ? 15 : 5));
		init();
		int l = -1, r = n;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (chk(mid)) r = mid;
			else l = mid;
		}
		printf("%d\n", r); 
	}	
}

void slv() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1, u, v; i < n; i++) read(u), read(v), e[u].pb(v), e[v].pb(u);
	if (ID <= 8) 
		SLV1::slv();
	else
		SLV2::slv();
}

bool MemED;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T;
	read(ID), read(T);
	while (T--) slv();
	
//	cerr << 1.0 * (&MemST - &MemED) / 1024. / 1024. << "MB" << endl; 
	return 0;
} 
