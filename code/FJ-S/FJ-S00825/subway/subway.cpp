#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int c, n, m, d, q, w[500005], k[505], a[500005], head[500005], to[1000005], nxt[1000005], cnt;
long long t[500005], val[1000005], dis[500005];
void add(int u, int v, long long va) {
	nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v, val[cnt] = va;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	if (9 <= c && c <= 11) {
		for (int i = 1; i <= m; ++i) scanf("%d", &w[i]);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &k[i]);
			if (k[i] == 1) continue;
			for (int j = 1; j <= 2; ++j)
				scanf("%d%lld", &a[j], &t[j]);
			add(a[1], a[2], t[1] + t[2]); add(a[2], a[1], t[1] + t[2]);
			for (int j = head[a[1]]; j; j = nxt[j]) {
				int flag = 0;
				for (int l = head[to[j]]; l; l = nxt[l]) {
					if (to[l] == a[2]) {
						if (val[l] > t[1] + t[2] + val[j]) {
							val[l] = t[1] + t[2] + val[j];
						}
						flag = 1;
						break;
					}
				}
				if (!flag) {add(to[j], a[2], t[1] + t[2] + val[j]); add(a[2], to[j], t[1] + t[2] + val[j]);}
			}
			for (int j = head[a[2]]; j; j = nxt[j]) {
				int flag = 0;
				for (int l = head[to[j]]; l; l = nxt[l]) {
					if (to[l] == a[1]) {
						if (val[l] > t[1] + t[2] + val[j]) {
							val[l] = t[1] + t[2] + val[j];
						}
						flag = 1;
						break;
					}
				}
				if (!flag) {add(to[j], a[1], t[1] + t[2] + val[j]); add(a[1], to[j], t[1] + t[2] + val[j]);}
			}
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			long long minn = 1LL << 62;
			for (int i = head[x]; i; i = nxt[i])
				if (to[i] == y && val[i] < minn) minn = val[i];
			for (int i = head[y]; i; i = nxt[i])
				if (to[i] == x && val[i] < minn) minn = val[i];
			printf("%lld\n", minn + w[x] + w[y]);
		}
	} else {
		for (int i = 1; i <= m; ++i) scanf("%d", &w[i]);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &k[i]);
			for (int j = 1; j <= k[i]; ++j)
				scanf("%d%lld", &a[j], &t[j]);
			for (int j = 1; j <= k[i]; ++j)
				for (int l = j + 1; l <= k[i]; ++l) {
					add(a[j], a[l], t[j] + t[l]); add(a[l], a[j], t[j] + t[l]);
				}
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			for (int i = 1; i <= m; ++i) dis[i] = 1LL << 62;
			dis[x] = 0;
			priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > qu;
			qu.push(make_pair(0, x));
			while (!qu.empty()) {
				auto u = qu.top(); qu.pop();
				for (int i = head[u.second]; i; i = nxt[i]) {
					int v = to[i];
					if (u.first + val[i] < dis[v]) {
						dis[v] = u.first + val[i];
						qu.push(make_pair(dis[v], v));
					}
				}
			}
			printf("%lld\n", dis[y] + w[x] + w[y]);
		}
	}
}
