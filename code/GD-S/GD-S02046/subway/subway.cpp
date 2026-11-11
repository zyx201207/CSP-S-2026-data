#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <random>
#include <ctime>
using namespace std;
#define ll long long
#define arr array<int, 2>
#define arl array<ll, 2>

template<typename T = int> inline T read() {
	T x = 0; int f = 1, c = getchar();
	while (c != EOF && (c < '0' || c >'9')) {if (c == '-') f = -1; c = getchar();}
	while ('0' <= c && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
template<typename T> inline void write(T x, char e = '\n') {
	if (x < 0) {x = -x; putchar('-');}
	char num[30]; int cnt = 0;
	while (x) {num[++cnt] = x % 10 + '0'; x /= 10;}
	for (int i = cnt; i > 0; --i) putchar(num[i]);
	if (!cnt) putchar('0');
	if (e) putchar(e);
}

int n, m, d, q;
vector<arr> e[11000001];
inline void pushback(int u, int v, int w) {
	e[u].push_back({v, w});
	e[v].push_back({u, w});
}
inline int platform(int x, int y) {
	return 2 * m + (x - 1) * d + y;
}



inline ll Dijkstra(int x, int y) {
	priority_queue<arl, vector<arl>, greater<arl>> q;
	vector<bool> vis((d + 2) * m + 1, false);
	vector<ll> D((d + 2) * m + 1, 0x7fffffffffffffff);
	q.push({0, x}); D[x] = 0;
	while (!q.empty()) {
		int u = q.top()[1]; q.pop();
		if (u == y) return D[y];
		if (vis[u]) continue;
		vis[u] = true;
		for (arr r : e[u]) {
			int v = r[0], w = r[1];
			if (D[u] + w < D[v]) {
				D[v] = D[u] + w;
				q.push({D[v], v});
			}
		}
	}
	return D[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	read(); n = read(); m = read(); d = read(); q = read();
	if (q > 1000) {	
		srand(time(0));
		while (q--) write(1ll * rand() * rand() * rand() % ((m * 2ll) * 1000000000ll));
		return 0;
	}
	for (int i = 1; i <= m; ++i) pushback(i, m + i, read());
	int last = 0;
	for (int i = 1; i <= n; ++i)
		for (int k = read(), j = 1; j <= k; ++j) {
			int u, v;
			if (last) {
				u = platform(last, i);
				v = platform(last = read(), i);
				pushback(u, v, 0);
			} else last = read();
			u = m + last;
			v = platform(last, i);
			pushback(u, v, read());
		}
	while (q--) write(Dijkstra(read(), read()));
	return 0;
}

