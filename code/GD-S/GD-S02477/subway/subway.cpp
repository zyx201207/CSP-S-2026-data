#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
using ll = long long ;
inline ll read() {ll res = 0;char ch = gc();ll flag = 1;while(!isdigit(ch)) {if(ch == '-') {flag = -flag;}ch = gc();}while(isdigit(ch)) {res = res*10+ch-48;ch = gc();}return res*flag;}
void write(ll x) {if(x < 0) {pc('-');x = -x;}if(x >= 10) {write(x/10);}pc(x%10+48);}

int const maxn = 5e5+5+500+5;
ll w[maxn];
int n,m,d;
ll dis[505][505]; // 只有线路的特殊点才需要求最短路

struct edge {
	int to;
	ll w;
	edge() {
		to = w = 0;
	}
	edge(int _to,ll _w) {
		to = _to;
		w = _w;
	}
};
vector<edge> g[maxn];  // 每个站点连接的线路
vector<edge> G[505]; // 每个线路连接的站点
vector<edge> e[505]; // 线路与线路之间建成的图 

struct inhp {
	int u;
	ll w;
	inhp() {
		u = w = 0;
	}
	inhp(int _u,ll _w) {
		u = _u;
		w = _w;
	}
	bool operator >(const inhp &ot) const {return w > ot.w;}
	bool operator <(const inhp &ot) const {return w < ot.w;}
};

inline void dijkstra(int x) {
	priority_queue<inhp,vector<inhp>,greater<inhp> > q;
	q.push(inhp(x,0));
	while(!q.empty()) {
		int u = q.top().u;
		ll w = q.top().w;
		q.pop();
		if(dis[x][u] != -1)  continue ;
		dis[x][u] = w;
		for(edge y : e[u]) {
			if(dis[x][y.to] != -1)  continue ;
			q.push(inhp(y.to,w+y.w));
		}
	}
}

inline ll qry(int x,int y) {
	ll ans = 9e18;
	for(edge u : g[x]) {
		for(edge v : g[y]) {
			ans = min(ans,u.w+v.w+dis[u.to][v.to]);
		}
	} 
	return ans;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,-1,sizeof dis);
	read(); // 测试点编号
	n = read();
	m = read();
	d = read();
	int q = read();
	for(int i = 1; i <= m; ++i)  w[i] = read();
	for(int i = 1; i <= n; ++i) {
		int k = read();
		while(k--) {
			int to = read();
			ll w = read();
			g[to].emplace_back(edge(i,w));
			G[i].emplace_back(edge(to,w));
		}
	}
	for(int i = 1; i <= n; ++i) {
		ll res[505];
		memset(res,0x3f,sizeof res);
		ll inf = res[0];
		for(edge y : G[i]) {
			for(edge z : g[y.to]) {
				res[z.to] = min(res[z.to],y.w+z.w);
			}
		}
		for(int j = 1; j <= n; ++j) {
			if(i == j or res[j] == inf)  continue ;
			e[i].emplace_back(edge(j,res[j]));
		}
	}
	for(int i = 1; i <= n; ++i)  dijkstra(i);
	while(q--) {
		int x = read(),y = read();
		write(qry(x,y) + w[x] + w[y]),pc(10);
	}
	return 0;
}





















