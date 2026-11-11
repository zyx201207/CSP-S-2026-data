#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	int to, l;
	node(int a, int b) {
		to = a, l = b;
	}
};
struct snode {
	int id, op;
//	snode(int a, int b) {
//		id = a, op = b;
//	}
};
const int M = 5e5 + 10, N = 510, Q = 1e5 + 10;
int n, m, c, h, q, w[M], d[N + M][2];
vector<node> e[N][2];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway1.in", "r", stdin);
//	freopen("subways.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &h, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++) {
			int x, y;
			scanf("%lld%lld", &x, &y);
			e[x][0].push_back(node(i, y));
			e[i][1].push_back(node(x, y));
		}
	}
	if (c <= 8) {
		while(q--) {
			int x, r;
			scanf("%lld%lld", &x, &r);
			for (int i = 1; i <= n; i++) {
				d[i][1] = (1LL << 62);
			}
			for (int i = 1; i <= m; i++) {
				d[i][0] = (1LL << 62);
			}
			d[x][0] = 0;
			while (true) {
				bool tt = true;
				for (int i = 1; i <= m; i++) {
					for (auto y : e[i][0]) {
						d[y.to][1] = min(d[y.to][1], d[i][0] + y.l);
					}
				}
				for (int i = 1; i <= n; i++) {
					for (auto y : e[i][1]) {
						int p = d[y.to][0];
						d[y.to][0] = min(d[y.to][0], d[i][1] + y.l);
						if (d[i][1] != (1LL << 62) && y.to == r && p == d[y.to][0]) {
							tt = false;
						}
					}
				}
				if (!tt) {
					break;
				}
			}
			printf("%lld\n", w[x] + w[r] + d[r][0]);
		}
	}
	if (c >= 12 && c <= 19) {
		while(q--) {
			int x, r;
			scanf("%lld%lld", &x, &r);
			for (int i = 1; i <= n; i++) {
				d[i][1] = (1LL << 62);
			}
			for (int i = 1; i <= m; i++) {
				d[i][0] = (1LL << 62);
			}
			d[x][0] = 0;
			snode q[N + M];
			q[1].id = x;
			q[1].op = 0;
			int front = 1, rear = 1;
			while (front <= rear) {
				int mop = q[front].op;
				int mid = q[front].id;
				front++;
				for (auto y : e[mid][mop]) {
					if (d[y.to][1 - mop] == (1LL << 62)) {
						d[y.to][1 - mop] = d[mid][mop] + y.l;
						q[++rear].id = y.to;
						q[rear].op = 1 - mop;
					}
				}
			}
			printf("%lld\n", w[x] + w[r] + d[r][0]);
		}
	}
	return 0;
}
