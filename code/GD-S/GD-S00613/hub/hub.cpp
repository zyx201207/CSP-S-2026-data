// D hub: 3s 1,024MiB, GREY.

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 1e6+5;
vector<int> G[maxn];
int Es[maxn], Ee[maxn], d[maxn], z[maxn][32], n;

int vat[maxn];
void init(int n) {
	for (int i = 1; i <= n; i++)
		vat[i] = i;
}
int find_root(int u) {
	if (vat[u] == u) return u;
	return vat[u] = find_root(vat[u]);
}
void meege(int u, int v) {
	int ru = find_root(u);
	int rv = find_root(v);
	vat[ru] = rv;
}

void ddd(int u, int vat) {
	d[u] = d[vat] + 1;
	z[u][0] = vat;
	for (int i = 1; i <= 25; i++)
		z[u][i] = z[z[u][i-1]][i-1];
	for (int v : G[u]) {
		if (v == vat) continue;
		ddd(v, u);
	}
}
inline int LCA(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = 25; i >= 0; i--) {
		if (d[z[u][i]] >= d[v])
			u = z[u][i];
	}
	if (u == v) return v;
	for (int i = 25; i >= 0; i--) {
		if (z[u][i] != z[v][i]) {
			u = z[u][i];
			v = z[v][i];
		}
	}
	return z[v][0];
}
inline int dis(int u, int v) {
	return d[u] + d[v] - 2*d[LCA(u, v)];
}

bool chk(int S, int n) {
	init(n);
	for (int i = 1; i < n; i++) {
		if ((S & (1 << (Es[i] - 1))) && (S & (1 << (Ee[i] - 1))))
			meege(Es[i], Ee[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (S & (1 << (i - 1)))
			if (find_root(i) == i) cnt++;
	if (cnt > 2) return false;
	return true;
}

int mian() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int n, k; 
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		Es[i] = u; Ee[i] = v;
	}
	ddd(1, 0);
	int ans = 0x3f3f3f3f;
	for (int S = 0; S < (1 << n); S++) {
		if (__builtin_popcount(S) != k) continue;
		if (!chk(S, n)) continue;
		int GXR = 0;
//		cerr << "now " << S << endl;
		for (int i = 1; i <= n; i++) {
			if (S & (1 << (i-1))) continue;
			int t = 0x3f3f3f3f;
			for (int j = 1; j <= n; j++) {
				if (S & (1 << (j-1))) {
					t = min(t, dis(i, j));
//					cerr << dis(i, j) << " " << i << " " << j << endl;
				}				
			}
			GXR = max(GXR, t);
		}
		ans = min(ans, GXR);
	}
	cout << ans << endl;
	return n;
}

int main() {
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n = mian();
		for (int i = 1; i <= n; i++)
			G[i].clear();
	}
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
