#include <bits/stdc++.h>
#define en puts("")
using namespace std;

typedef long long ll;
const ll inf = 8e18;

inline ll rd(){
	char c;
	bool flag = 0;
	while((c = getchar()) != EOF && (c < '0' || c > '9')){
		flag = (c == '-');
	}
	ll res = c - '0';
	while((c = getchar()) != EOF && (c >= '0' && c <= '9')){
		res = (res << 3) + (res << 1) + c - '0';
	}
	return flag ? -res : res;
}

inline void wr(ll x){
	if (x < 0){
		putchar('-');
	}else{
		if (x > 9) wr(x / 10);
		putchar(x % 10 + '0');
	}
}

struct edge{
	int to,next;
	ll w;
}e[200000];int h[200005],ecnt;

void add(int u,int v,ll w){
	e[++ecnt] = {v,h[u],w};
	h[u] = ecnt;
}

struct question{
	int l,r,id;
	
	bool operator < (const question qu) const{
		return (l != qu.l) ? l < qu.l : r < qu.r;
	}
	
}ask[100005];

vector <int> sub[506];
vector <int> S[20006];
int id,n,m,d,q;
int w[500005];
ll dis[500005];
ll ans[500005];
int t[406][206];
bool vis[500005];

int check(){
	if (id <= 6) return 1;
	return 2;
}

priority_queue < pair <ll,int> > Q;
pair <ll,int> cnt;

void solve(int start){
	for (int i = 1; i <= m; ++i){
		vis[i] = 0;
		dis[i] = inf;
	}
	dis[start] = 0;
	Q.push(make_pair(0,start));
	while(!Q.empty()){
		int u = Q.top().second;
		Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int subway : S[u]){
			for (int to : sub[subway]){
				if (dis[to] > dis[u] + t[u][subway] + t[to][subway]){
					dis[to] = dis[u] + t[u][subway] + t[to][subway];
					cnt.first = -dis[to],cnt.second = to;
					Q.push(cnt);
				}
			}
		}
	}
}

void dijkstra(int start){
	for (int i = 1; i <= n; ++i){
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[start] = 0;
	Q.push(make_pair(0,start));
	while(!Q.empty()){
		int u = Q.top().second;
		Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = e[i].next){
			int v = e[i].to,w = e[i].w;
			if (dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				Q.push(make_pair(-dis[v],v));
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	id = rd(),n = rd(),m = rd(),d = rd(),q = rd();
	for (int i = 1; i <= m; ++i){
		w[i] = rd();
	}
	if (check() == 1){
		for (int i = 1; i <= n; ++i){
			int k = rd();
			for (int j = 1; j <= k; ++j){
				int x = rd();
				t[x][i] = rd();
				sub[i].push_back(x);
				S[x].push_back(i);
			}
		}
		for (int i = 1; i <= q; ++i){
			ask[i].l = rd(),ask[i].r = rd(),ask[i].id = i;
		}
		sort(ask + 1,ask + 1 + q);
		ask[q + 1].l = m + 1;
		int p = 1;
		for (int i = 1; i <= m; ++i){
			if (ask[p].l > i) continue;
			solve(i);
			while(ask[p].l == i){
				ans[ask[p].id] = dis[ask[p].r] + w[ask[p].l] + w[ask[p].r];
				++p;
			}
		}
	}else{
		for (int i = 1; i <= n; ++i){
			int k = rd();
			int root = rd(),T = rd();
			t[root][i] = T;
			for (int j = 1; j < k; ++j){
				int x = rd(),t = rd();
				add(x,root,T + t);
				add(root,x,T + t);
			}
		}
		for (int i = 1; i <= q; ++i){
			ask[i].l = rd(),ask[i].r = rd();ask[i].id = i;
		}
		sort(ask + 1,ask + 1 + q);
		ask[q + 1].l = m + 1;
		int p = 1;
		for (int i = 1; i <= m; ++i){
			if (ask[p].l > i) continue;
			dijkstra(i);
			while(ask[p].l == i){
				ans[ask[p].id] = dis[ask[p].r] + ans[ask[p].l] + ans[ask[p].r];
				++p;
			}
		}
	}
	for (int i = 1; i <= q; ++i){
		wr(ans[i]);
		en;
	}
	return 0;
}
