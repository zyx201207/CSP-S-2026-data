#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int N = 5e5 + 510, M = 505;
int c, n, m, lim, q, a[N], idx, h[N], d[M][M], dd[N];
bool vis[N];
struct edge{
	int ne, to, w;
}e[N << 1];
void add(int x, int y, int w){
	e[++idx] = {h[x], y, w};
	h[x] = idx;
}
void dij(int st){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	int need = n;
	for (int i = 1; i <= n; i++){
		if (d[i][st]) need--, dd[i + m] = d[st][i] = d[i][st];
	}
	if (!need) return;
	q.push({0, st + m});
	dd[st + m] = 0;
	unordered_set<int> dl;
	dl.insert(st + m);
	while (!q.empty()){
		int u = q.top().first, v = q.top().second;
		q.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		if (v > m && !d[st][v - m]){
			need--;
			if (!need){
				break;
			}
		}
		for (int i = h[v]; i; i = e[i].ne){
			int j = e[i].to;
			if (dd[j] > u + e[i].w){
				dl.insert(j);
				dd[j] = u + e[i].w;
				q.push({dd[j], j});
			}
		}
	}
	for (int i = 1; i <= n; i++){
		d[st][i] = dd[i + m];
	}
	for (auto i : dl){
		vis[i] = 0;
		dd[i] = dd[0];
	}
}
void bfs(int st){
	queue<int> q;
	int need = n;
	for (int i = 1; i <= n; i++){
		if (d[i][st]) need--, dd[i + m] = d[st][i] = d[i][st];
	}
	if (!need) return;
	q.push(st + m);
	dd[st + m] = 0;
	unordered_set<int> dl;
	dl.insert(st + m);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		if (v > m && !d[st][v - m]){
			need--;
			if (!need){
				break;
			}
		}
		for (int i = h[v]; i; i = e[i].ne){
			int j = e[i].to;
			if (dd[j] > dd[v] + e[i].w){
				dl.insert(j);
				dd[j] = dd[v] + e[i].w;
				q.push(j);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (!d[st][i]) d[st][i] = dd[i + m];
	}
	d[st][st] = 0;
	for (int i : dl){
		vis[i] = 0;
		dd[i] = dd[0];
	}
}
signed main(){
	memset(dd, 0x3f, sizeof dd);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &lim, &q);
	for (int i = 1; i <= m; i++){
		scanf("%lld", &a[i]);
	}
	for (int i = 1, k, t, c; i <= n; i++){
		scanf("%lld", &k);
		while (k--){
			scanf("%lld%lld", &t, &c);
			add(t, i + m, c);
			add(i + m, t, c);
		}
	}
	for (int i = 1; i <= n; i++){
		if (12 <= c && c <= 19) bfs(i);
		else dij(i);
	}
	for (int i = 1, x, y; i <= q; i++){
		scanf("%lld%lld", &x, &y);
		int ans = 1e17;
		for (int j = h[x]; j; j = e[j].ne){
			for (int k = h[y]; k; k = e[k].ne){
				ans = min(ans, e[j].w + d[e[j].to - m][e[k].to - m] + e[k].w);
			}
		}
		printf("%lld\n", ans + a[x] + a[y]);
	}
	return 0;
}
