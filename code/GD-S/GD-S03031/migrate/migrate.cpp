#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 2e6 + 10;
const int MAXM = 2e6 + 10;
const long long INF = 4e18 + 10;

int c, T, n;
LL d, a[MAXN];

struct edg {
	int v;
	LL w;
};
vector<edg> G[MAXM];

bool vis[MAXM];
LL dis[MAXM], cnt[MAXM];
LL Dijkstra(int s, int tt) {
	priority_queue< pair<LL, int>, vector<pair<LL, int> >,  greater<pair<LL, int> > > PQ;
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
		vis[i] = 0;
		cnt[i] = 0;
	}
	dis[s] = 0;
	PQ.push({0, s});
	vis[s] = 1;
	while (!PQ.empty()) {
		int u = PQ.top().second;
		int disu = PQ.top().first;
		vis[u] = 1;
		PQ.pop();
		for (auto e : G[u]) {
			int v = e.v;
			LL w = e.w;
			if (vis[v]) continue;
			if (dis[v] != INF && dis[v] == disu + w) cnt[v] ++;
			if (dis[v] > disu + w) {
				dis[v] = disu + w;
				PQ.push({dis[v], v});
			}
		}
	}
	return dis[tt];
}

void work() {
	scanf("%d%lld", &n, &d); 
//	vector<LL> x(n + 5);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		G[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (abs(a[i] - a[j]) <= d) {
				G[i].push_back({j, abs(a[i] - a[j])});
				G[j].push_back({i, abs(a[i] - a[j])});
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		LL tmp = Dijkstra(i, n);
		for (int j = i + 1; j <= n; j++) {
//			cout << cnt[j] << " ";
			if (cnt[j] == 2) ans ++;
		}
//		cout << "\n";
	}
	printf ("%d\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf ("%d%d", &c, &T);
	while (T --) {
		work();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
