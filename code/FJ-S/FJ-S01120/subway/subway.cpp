#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 500000 + 5000, N = 550;
const int D = 25;
int w[M];
struct node {
	int nxt, to, val;
} edge[M * D];
int cnt = 0, h[M];
int vis[N];
ll Ed[N][N];
ll solve(int x, int y) {
	ll ans = 1000000000000000000;
	for (int i = h[x]; i; i = edge[i].nxt) {
		for (int j = h[y]; j; j = edge[j].nxt) {
			int ito = edge[i].to, jto = edge[j].to;
			int vali = edge[i].val, valj = edge[j].val;
//			cout << ito << ' ' << jto << endl;
			ans = min(ans, 1ll * vali + valj + Ed[ito][jto] + w[x] + w[y]);
		} 
	}
	return ans;
}
void add(int x, int y, int z) {
	edge[++cnt] = (node) {h[x], y, z};
	h[x] = cnt; 
	return;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]); 
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a, t;
			scanf("%d%d", &a, &t);
			add(a, i, t); 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				Ed[i][j] = 0;
				continue;
			}
			Ed[i][j] = 1000000000000000000;
		}
	}
	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			vis[j] = 0;
//		}
		for (int jj = h[i]; jj; jj = edge[jj].nxt) {
			int y = edge[jj].to, valy = edge[jj].val;
//			vis[y] = 1;
			for (int kk = h[i]; kk; kk = edge[kk].nxt) {
				int z = edge[kk].to, valz = edge[kk].val;
				if (z == y) {
					continue;
				}
				Ed[z][y] = Ed[y][z] = min(1ll * valy + 1ll * valz, Ed[z][y]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) {
				continue;
			}
			for (int j = 1; j <= n; j++) {
				if (k == j || j == i) {
					continue;
				}
				if (Ed[i][j] > Ed[i][k] + Ed[k][j]) {
					Ed[i][j] = Ed[i][k] + Ed[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", solve(x, y));
	} 
	return 0;
}
// 0 3 6 5 10

