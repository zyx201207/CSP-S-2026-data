//GZ-S00267 贵阳华师一 冯子尧 
#include <bits/stdc++.h>
#define upp(a, x, y) for (int a = x; a <= y; a++)
#define dww(a, x, y) for (int a = x; a >= y; a--)
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;

const int N = 5e5 + 200, M = 60;

int c, n, m, d, q;
LL w[N];
vector<PIL> g[N];
map<int , map<int, LL> > dist;
bool st[N];

void add(int a, int b, LL c) {
	g[a].pb({b, c});
	g[b].pb({a, c});
}

LL Dijkstra(int s, int t) {
	memset(st, 0, sizeof st);
	priority_queue<PLI, vector<PLI>, greater<PLI> > heap;
	heap.push({0ll, s});
	while (heap.size()) {
		PLI nt = heap.top();
		heap.pop();
		dist[s][nt.second] = dist[nt.second][s] = min(dist[s][nt.second], nt.first);
		int sl = g[nt.second].size();
		for (int i = 0; i < sl; i ++) {
			PIL edge = g[nt.second][i];
			int e = edge.first;
			LL d = edge.second;
			if (st[e]) continue;
			heap.push({nt.first + d, e});
			st[e] = true;
			dist[s][e] = dist[e][s] = min(dist[s][e], nt.first + d);
			if (e == t) return nt.first + d;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, %d, &q);
	cin >> c >> n >> m >> d >> q;
	upp(i, 1, m) scanf("%lld", &w[i]);
	upp(i, 1, n) {
		int k;
		scanf("%d", &k);
		upp(j, 1, k) {
			int a, t;
			scanf("%d%d", &a, &t);
			add(a, m + i, t);
		}
	}
	while (q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		if (dist[s][t] != 0) {
			printf("%lld\n", dist[s][t]);
			continue;
		}
		LL res = w[s] + w[t];
		res += Dijkstra(s, t);
		dist[s][t] = dist[t][s] = res;
		printf("%lld\n", res);
	}
	return 0;
}
