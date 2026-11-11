#include<bits/stdc++.h>
using namespace std;
using lint = long long;
const int maxn = 5e5 + 505;
int w[maxn]; 
long long dis[maxn];
int head[maxn], to[maxn << 1], wgt[maxn << 1], nxt[maxn << 1], tot = 1;
void add_edge(int u, int v, int w) {
	to[++ tot] = v;
	wgt[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot;
}
long long ans[maxn];
struct node {
	int i, j;
} qry[maxn];
priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++) cin >> w[i];
	for (int i = 1 ; i <= n ; i ++) {
		int k;
		cin >> k;
		for (int j = 1 ; j <= k ; j ++) {
			int to, val;
			cin >> to >> val;
			add_edge(i + m, to, val);
			add_edge(to, i + m, val);
		}
	}
	memset(ans, 0x3f, sizeof ans);
	for (int i = 1 ; i <= q ; i ++) cin >> qry[i].i >> qry[i].j;
	for (int i = 1 ; i <= n ; i ++) {
			pq.push({0, i + m});
			for (int j = 1 ; j <= n + m ; j ++) dis[j] = 1e17;
			dis[i + m] = 0;
			while (pq.size()) {
				auto top = pq.top(); pq.pop();
				int u = top.second , d = top.first;
				if (d > dis[u]) continue; 
				for (int j = head[u] ; j ; j = nxt[j]) {
					int v = to[j] , w = wgt[j];
					if (dis[v] > dis[u] + w) {
						dis[v] = dis[u] + w;
						pq.push({dis[v], v});
					}
	 			}
			}
		for (int i = 1 ; i <= q ; i ++) {
			ans[i] = min(ans[i], dis[qry[i].i] + dis[qry[i].j]);
		}
	}
	for (int i = 1 ; i <= q ; i ++) cout << ans[i] + w[qry[i].i] + w[qry[i].j] << '\n';
	return 0;
}

