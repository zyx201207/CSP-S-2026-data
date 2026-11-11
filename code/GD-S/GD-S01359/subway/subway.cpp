#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 505, M = 5e5 + 505, Q = 1e5 + 5;
vector<pair<int, int>> g[M];
struct plan {
	int x;
	int y;
	int id;
};
plan temp[Q];
void merge_sort(plan* a, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r) {
		if (a[i].x > a[j].x) temp[p++] = a[j++];
		else temp[p++] = a[i++];
	}
	while (i <= mid) temp[p++] = a[i++];
	while (j <= r) temp[p++] = a[j++];
	for (p = l; p <= r; ++p) a[p] = temp[p];
}

LL dis[M];
int heap[M], idx[M];
void up(int i) {
	while (i != 1 && dis[heap[i]] < dis[heap[i >> 1]]) {
		swap(heap[i], heap[i >> 1]);
		swap(idx[heap[i]], idx[heap[i >> 1]]);
		i >>= 1;
	}
}
void push(int u) {
	heap[++heap[0]] = u;
	idx[u] = heap[0];
	up(heap[0]);
}
void down(int i) {
	int j;
	while ((i << 1) <= heap[0]) {
		j = (i << 1);
		if (j + 1 <= heap[0] && dis[heap[j + 1]] < dis[heap[j]])
			++j;
		if (dis[heap[j]] < dis[heap[i]]) {
			swap(heap[i], heap[j]);
			swap(idx[heap[i]], idx[heap[j]]);
			i = j;
		} else break;
	}
}
void pop() {
	swap(heap[1], heap[heap[0]]);
	swap(idx[heap[1]], idx[heap[heap[0]]]);
	idx[heap[heap[0]--]] = -1;
	down(1);
}

void dijkstra(int n, int s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0LL;
	for (int i = 1; i <= n; ++i) {
		push(i);
	}
	int u, v, w;
	for (int i = 1; i <= n; ++i) {
		u = heap[1]; pop();
		for (int j = 0; j < g[u].size(); ++j) {
			v = g[u][j].first, w = g[u][j].second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				up(idx[v]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[M];
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	int k[N], a, t;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	
	plan que[Q];
	for (int i = 1; i <= q; ++i) {
		cin >> que[i].x >> que[i].y;
		que[i].id = i;
	}
	merge_sort(que, 1, q);
	int s = 0;
	LL ans[Q];
	for (int i = 1; i <= q; ++i) {
		if (s != que[i].x) {
			s = que[i].x;
			dijkstra(n + m, que[i].x);
		}
		ans[que[i].id] = dis[que[i].y] + w[que[i].x] + w[que[i].y];
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}

