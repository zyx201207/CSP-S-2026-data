#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
using ll = long long ;
inline ll read() {ll res = 0;char ch = gc();ll flag = 1;while(!isdigit(ch)) {if(ch == '-') {flag = -flag;}ch = gc();}while(isdigit(ch)) {res = res*10+ch-48;ch = gc();}return res*flag;}
void write(ll x) {if(x < 0) {pc('-');x = -x;}if(x >= 10) {write(x/10);}pc(x%10+48);}

int const maxn = 2e6+5;
vector<int> g[maxn];
int dep[maxn];
// Ñ°ÕÒ lca ÒÔ¼ÆËãÁ©µã¾àÀë
int tp[maxn],hson[maxn],se[maxn];
int fa[maxn];

void dfs(int x,int f) {
	hson[x] = 0;
	se[x] = 1;
	fa[x] = f;
	dep[x] = dep[f] + 1;
	for(int y : g[x]) {
		if(y == f)  continue ;
		dfs(y,x);
		se[x] += se[y];
		if(se[y] >= se[hson[x]])  hson[x] = y;
	}
} 
void dfs2(int x,int t) {
	tp[x] = t;
	if(hson[x])  dfs2(hson[x],t);
	else  return ;
	for(int y : g[x]) {
		if(y == hson[x] or y == fa[x])  continue ;
		dfs2(y,y);
	}
}
inline int lca(int x,int y) {
	while(tp[x] != tp[y]) {
		if(dep[tp[x]] < dep[tp[y]])  swap(x,y);
		x = fa[tp[x]];
	}
	return dep[x] > dep[y] ? y : x;
}
int uft[maxn];
int find(int x) {
	return uft[x] == x ? x: uft[x] = find(uft[x]);
}

inline int lowbit(int x) {
	return (x&(-x));
}
inline int coubit(int x) {
	int cnt = 0;
	while(x) {
		++cnt;
		x ^= lowbit(x);
	}
	return cnt;
}
inline int dis(int x,int y) {
	return dep[x] + dep[y] - 2*dep[lca(x,y)];
}

inline void work() {
	dep[0] = -1;
	int n = read();
	int k = read();
	vector<pair<int,int> > e;
	for(int i = 1; i <= n; ++i)  g[i].clear();
	for(int i = 1; i < n; ++i) {
		int u = read(),v = read();
		e.emplace_back(make_pair(u,v));
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1,0);
	dfs2(1,1);
	int ans = n;
	for(int sta = 0;sta < (1ll<<n); ++sta) {
		if(!sta)  continue ;
		for(int i = 1; i <= n; ++i)  uft[i] = i;
		int res = 0;
		if(coubit(sta) > k)  continue ;
		for(pair<int,int> y : e) {
			if(sta >> (y.first-1) & 1) {
				if(sta >> (y.second-1) & 1) {
					uft[find(y.first)] = find(y.second);
				}
			}
		}
		set<int> s;
		for(int i = 1; i <= n; ++i) {
			if(sta >> (i-1) & 1) {
				s.insert(find(i));
			}
		}
		if(s.size() > 2) continue ;
		for(int i = 1; i <= n; ++i) {
			int r = n;
			for(int j = 1; j <= n; ++j) {
				if(sta >> (j-1) & 1) {
					r = min(r,dis(i,j));
				}
			}
			res = max(res,r);
		}
		ans = min(ans,res);
	}
	write(ans),pc(10);
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();
	int T = read();
	while(T--)  work();
	return 0;
}





















