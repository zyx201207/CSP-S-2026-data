#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sizf(x) ((int)(x).size())
#define report(...) fprintf(stderr, __VA_ARGS__)

inline ll read(void) {
	ll x=0,f=1; int ch;
	while (!isdigit(ch=getchar())) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}

bool Mst;

const int N = 1e6+5, inf = 1e9;
int n, k;

vector<pair<int, int> > E;
vector<int> t[N];

int dis[N], fa[N];
void init(void) {
	for (int i = 0; i < n; i++) fa[i] = i, dis[i] = inf;
}

inline int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
inline void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return ;
	fa[x] = y;
}

bool Med;

int main(void)
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int cid = read();
	int test = read();
	
	while (test--) {
		n = read(); k = read();
	
		E.clear();
		for (int i = 0; i < n; i++) t[i].clear();
		for (int i = 1; i < n; i++) {
			int u = read(); int v = read();
			u--; v--;
			E.emplace_back(u, v);
			t[u].emplace_back(v);
			t[v].emplace_back(u);
		}
		
		int ans = inf;
		for (int s = 0; s < (1 << n); s++) {
			if (__builtin_popcount(s) != k) continue;
			init();
			for (auto e : E) {
				if ((s>>e.fi&1) && (s>>e.se&1)) {
					merge(e.fi, e.se);
				}
			}
			int cnt = 0;
			for (int i = 0; i < n; i++) if (s>>i&1) cnt += fa[i] == i;
			if (cnt > 2) continue;
			
			queue<int> q;
			for (int i = 0; i < n; i++) if (s>>i&1) q.push(i), dis[i] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (auto v : t[u]) {
					if (dis[v] == inf) dis[v] = dis[u] + 1, q.push(v);
				}
			}
			
			int ret = 0;
			for (int i = 0; i < n; i++) ret = max(ret, dis[i]);
			
			ans = min(ans, ret);
		}
		printf("%d\n", ans);
	}
	
	report("Mem : %lf MB\n", abs(&Med - &Mst) / 1024.0 / 1024.0);
	report("Time: %lf s\n", 1.0 * clock() / CLOCKS_PER_SEC);
	return 0;
}
