#include<bits/stdc++.h>
using namespace std;
uint8_t buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 =(p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1++)
int readint() {
	int k = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) {
		if (c == '-')
			f = -1;
	}
	for (; isdigit(c); c = gc()) {
		k = k * 10 + (c - '0');
	}
	return f * k;
}

long long readll() {
	long long k = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) {
		if (c == '-')
			f = -1;
	}
	for (; isdigit(c); c = gc()) {
		k = k * 10 + (c - '0');
	}
	return f * k;
}
/*
int readint() {
	int x;
	cin >> x;
	return x;
}
*/
const int N = 505, M = 500005;
int n, m, d, q;
vector<int> w, a[N], t[N];
vector<uint64_t> dis[N];
//n = subway mun, m = zhan mun;

struct star {
	size_t idx = 0; 
	vector<int> head, to, wi, nex;
	
	void init (size_t _size) {
		head.resize(_size + 1);
		to.resize(1, 0);
		wi.resize(1, 0);
		nex.resize(1, 0);
		to.reserve(2 * d * m + 1);
		wi.reserve(2 * d * m + 1);
		nex.reserve(2 * d * m + 1);
	}
	
	void add(int u, int v, int c) {
		++idx;
		to.push_back(v);
		wi.push_back(c);
		nex.push_back(head[u]);
		head[u] = idx;
	}
}adj;

void dji(int root) {
	priority_queue <pair<uint64_t, int>, vector<pair<uint64_t, int>>, greater<pair<uint64_t, int>>> q;
	vector<bool> vis(m + n + 1, false);
	vector<uint64_t> dist(m + n + 1, 0x3fffffffffffffff);
	dist[root] = 0;
	q.push({0, root});
	while (!q.empty()) {
		auto top = q.top();
		int u = top.second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = adj.head[u]; i; i = adj.nex[i]) {
			int v = adj.to[i];
			if (vis[v])
				continue;
			dist[v] = min(dist[v], dist[u] + adj.wi[i]);
			q.push({dist[v], v});
		}
	}
	dis[root - m] = dist;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c = readint();
	n = readint();
	m = readint();
	d = readint();
	q = readint();
	w.resize(m + 1);
	adj.init(m + n);
	for (int i = 1; i <= m; i++) {
		w[i] = readint();
	}
	for (int i = 1; i <= n; i++) {
		int k = readint();
		a[i].resize(k + 1);
		t[i].resize(k + 1);
		for (int j = 1; j <= k; j++) {
			a[i][j] = readint();
			t[i][j] = readint();
			adj.add(a[i][j], m + i, t[i][j]);
			adj.add(m + i, a[i][j], t[i][j]);
		}	
	}
	for (int i = 1; i <= n; i++) {
		dji(m + i);
	}
	for (int i = 1; i <= q; i++) {
		int x = readint(), y = readint();
		uint64_t ans = 0x3fffffffffffffff;  
		for (int i = adj.head[x]; i; i = adj.nex[i]) {
			int v = adj.to[i] - m;
			ans = min(ans, adj.wi[i] + dis[v][y]);
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
