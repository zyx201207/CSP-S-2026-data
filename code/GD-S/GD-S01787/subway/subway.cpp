#include<bits/stdc++.h>
using namespace std;
#define vec std::vector
#define ll long long
#define i128 __int128
#define endl "\n"
ll read(){
	ll num = 0; int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = (num << 1) + (num << 3) + (c ^ 48);
		c = getchar();
	}
	return num * f;
}
constexpr int N = 505, M = 1e5 + 5;
int id, n, m, d, q;
struct Node{
	int to, nxt;
	ll val;
}e[(M<<1) + (N<<1)];
int head[(M<<1) + N], cnt;
void add(int u, int v, ll w) {
	e[++ cnt] = {v, head[u], w};
	head[u] = cnt;
}
ll dis[(M<<1)+N];
bool vis[(M<<1)+N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	id = read(), n = read(), m = read(), d = read(), q = read();
	int tot = m;
	for (int i = 1; i <= m; ++i) {
		ll w = read();
		++tot;
		add(i, tot, w), add(tot, i, w);
	}
	for (int i = 1; i <= n; ++i) {
		int k = read();
		++tot;
		for (int j = 1; j <= k; ++j) {
			int node = read(); ll w = read();
			add(node + m, tot, w), add(tot, node + m, w);
		}
	}
	priority_queue<pair<ll, int>, vec<pair<ll, int>>, greater<pair<ll, int>> > Q;
	while (q --) {
		while (!Q.empty()) Q.pop();
		int s = read(), t = read();
		for (int i = 1; i <= 2 * (m + n); ++i) dis[i] = 4e18, vis[i] = false;
		Q.push({0, s});
		dis[s] = 0;
		while (!Q.empty()){
			int u = Q.top().second;
			Q.pop();
			if (vis[u]) continue;
			vis[u] = true;
//			cout << "u:" << u << endl;
			for (int i = head[u]; i; i = e[i].nxt) {
				int v = e[i].to;
				if (dis[v] > dis[u] + e[i].val) {
					dis[v] = dis[u] + e[i].val;
					Q.push({dis[v], v});
				}
			}
		}
		cout << dis[t] << endl;
	}
	return 0;
}

