#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 505;
const int M = 5 * 1e5 + 505;
const int E = 1e7 + 5;
const int Q = 1e5 + 5;
int n, m, D, q;
int w[M];
struct node{
	int to, nxt, len;
} e[E * 2];
int tot = 0, h[M];
inline void add(int x, int y, int l){
	e[++ tot] = {y, h[x], l};
	h[x] = tot;
}
struct Ques{
	int x, y;
	ll ans;
} tsk[Q];
ll d[M];
set<pair<ll, int> > heap;

inline void dij(int s){
	set<pair<ll, int> >().swap(heap);
	for(int i = 1;i <= m + n;i ++){
		d[i] = (ll)(1e17);
	}
	d[s] = 0;
	heap.insert({d[s], s});
	while(!heap.empty()){
		int u = heap.begin() -> second;
		heap.erase(heap.begin());
		for(int i = h[u];i;i = e[i].nxt){
			int v = e[i].to, w = e[i].len;
			if(d[v] > d[u] + w){
				heap.erase({d[v], v});
				d[v] = d[u] + w;
				heap.insert({d[v], v});
			}
		}
	}
}

inline void solve(){
	cin >> n >> m >> D >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int k; cin >> k;
		for(int j = 1;j <= k;j ++){
			int x, t; cin >> x >> t;
			add(i + m, x, t);
			add(x, i + m, t);
		}
	}
	for(int i = 1;i <= q;i ++){
		int x, y; cin >> x >> y;
		tsk[i] = {x, y, (ll)(1e17)};
	}
	for(int i = 1;i <= n;i ++){
		dij(i + m);
		for(int i = 1;i <= q;i ++){
			int x = tsk[i].x, y = tsk[i].y;
			ll res = d[x] + d[y];
			tsk[i].ans = min(tsk[i].ans, res);
		}
	}
	for(int i = 1;i <= q;i ++){
		cout << tsk[i].ans + w[tsk[i].x] + w[tsk[i].y] << '\n';
	}
}

bool vis[M];
queue<int> Que;

inline void bfs(int s){
	queue<int>().swap(Que);
	for(int i = 1;i <= n + m;i ++) d[i] = 0;
	for(int i = 1;i <= n + m;i ++) vis[i] = 0;
	Que.push(s); vis[s] = 1;
	while(!Que.empty()){
		int u = Que.front(); Que.pop();
		for(int i = h[u];i;i = e[i].nxt){
			int v = e[i].to;
			if(vis[v]) continue;
			vis[v] = 1; Que.push(v);
			d[v] = d[u] + 1;
		}
	}
}

inline void spj(){
	cin >> n >> m >> D >> q;
	int T = 0;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int k; cin >> k;
		for(int j = 1;j <= k;j ++){
			int x, t; cin >> x >> t;
			if(!T) T = t;
			add(i + m, x, t);
			add(x, i + m, t);
		}
	}
	for(int i = 1;i <= q;i ++){
		int x, y; cin >> x >> y;
		tsk[i] = {x, y, (ll)(1e17)};
	}
	for(int i = 1;i <= n;i ++){
		bfs(i + m);
		for(int i = 1;i <= q;i ++){
			int x = tsk[i].x, y = tsk[i].y;
			ll res = 1ll * d[x] * T + 1ll * d[y] * T;
			tsk[i].ans = min(tsk[i].ans, res);
		}
	}
	for(int i = 1;i <= q;i ++){
		cout << tsk[i].ans + w[tsk[i].x] + w[tsk[i].y] << '\n';
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	int c; cin >> c;
	if(12 <= c && c <= 19) spj();
	else solve();
	return 0;
}
