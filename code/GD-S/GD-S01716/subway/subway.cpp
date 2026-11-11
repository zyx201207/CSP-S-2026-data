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
#define sz(x) (int)x.size()
#define bk(x) x.back()
#define all(x) x.begin(), x.end()

const int N = 505;
const int M = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
void read(int &x) {
	x = 0;
	char ch = gc();
	while (ch < '0' || ch > '9') ch = gc();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
}

int ID, n, m, d, q;
int w[M] = {0};
struct Edge {
	int to, val;
	Edge (int _to = 0, int _val = 0) :
		to(_to), val(_val) {}
};
vector<Edge> e[M];

ll mtr[N][N] = {{0}};

void cmn(ll &x, ll y) {
	x = min(x, y);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(ID), read(n), read(m), read(d), read(q);
	for (int i = 1; i <= m; i++) read(w[i]);
	for (int i = 1, k, x, y; i <= n; i++) {
		read(k);
		while (k--) {
			read(x), read(y);
			e[x].eb(i, y);
		}
	}
	memset(mtr, 0x3f, sizeof mtr);
	for (int i = 1; i <= n; i++) mtr[i][i] = 0ll;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < sz(e[i]); j++)
			for (int k = j + 1; k < sz(e[i]); k++) {
				int u = e[i][j].to, v = e[i][k].to;
				ll cst = e[i][j].val + e[i][k].val;
				cmn(mtr[u][v], cst);
				cmn(mtr[v][u], cst);
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cmn(mtr[i][j], mtr[i][k] + mtr[k][j]);
	for (int i = 1, x, y; i <= q; i++) {
		read(x), read(y); 
		ll res = inf;
		for (auto j: e[x])
			for (auto k: e[y]) {
				int u = j.to, v = k.to;
				ll cst = j.val + k.val;
				cmn(res, mtr[u][v] + cst + w[x] + w[y]);
			}
		printf("%lld\n", res);
	}
	return 0;
} 
