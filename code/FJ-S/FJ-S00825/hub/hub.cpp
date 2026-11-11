#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, u, v, head[500005], to[1000005], nxt[1000005], cnt;
long long val[1000005], dis[500005];
void add(int u, int v, long long va) {
	nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v, val[cnt] = va;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		long long maxn = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v, 1); add(v, u, 1);
		}
		priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > qu;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++i) dis[j] = 1LL << 62;
			dis[i] = 0;
			long long minn = 1LL << 62;
			qu.push(make_pair(0, i));
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
			for (int j = 1; j <= n; ++j) {
				if (j != i && dis[j] < minn) minn = dis[j];
			}
			if (minn > maxn) maxn = minn;
		}
		printf("%lld\n", maxn);
	}
}
