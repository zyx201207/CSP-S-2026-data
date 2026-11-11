#include<bits/stdc++.h>
using namespace std;
constexpr int N=4005;
int n, k;
vector<int> e[N];
int f[N][N], siz[N], g[N], mxdep[N], dep[N], mx[N], sec[N], out[N];
void dfs(int x, int fa) {
	siz[x]=1;
	mxdep[x]=dep[x];
	for(int i=0; i<=n; i++) f[x][i]=0;
	for(auto v : e[x]) {
		if(v==fa) continue;
		dep[v]=dep[x]+1;
		dfs(v, x);
		if(mxdep[v]>mxdep[x]) {
			sec[x]=mx[x];
			mx[x]=v;
		} else {
			if(mxdep[v]>mxdep[sec[x]]) {
				sec[x]=v;
			}
		}
		mxdep[x]=max(mxdep[x], mxdep[v]);
		for(int i=1; i<=siz[x]; i++) {
			for(int j=0; j<=siz[v]; j++) {
				g[i+j]=min(g[i+j], max(f[x][i], j?f[v][j]:mxdep[v]-dep[x]));
			}
		}
		siz[x]+=siz[v];
		f[x][0]=max(f[x][0],mxdep[v]-dep[x]);
		for(int i=1; i<=siz[x]; i++) {
			f[x][i]=g[i];
			g[i]=1e9;
		}
	}
}
vector<int> hav[N];
void dfs1(int x, int fa) {
	for(auto v : e[x]) {
		if(v==fa) continue;
		if(mx[x]==v) {
			out[v]=max(out[v], max(out[x]+1, dep[x]-mxdep[sec[x]]+1));
		} else {
			out[v]=max(out[v], max(out[x]+1, dep[x]-mxdep[mx[x]]+1));
		}
		dfs1(v, x);
	}
}
int res;
void dfs2(int x, int fa) {
	int now=0;
	for(auto v : e[x]) {
		if(v==fa) continue;
		dfs2(v, x);
		if(v!=mx[x] && v!=sec[x]) now=max(now, mxdep[v]);
	}
	if(mxdep[x]<out[x]) {
		hav[x].push_back(x);
		for(auto v : e[x]) {
			if(v==fa) continue;
			for(auto a : hav[v]) {
				hav[x].push_back(v);
			}
		}
		return;
	}
	res=min(res, max(f[x][k], out[x]));
	if(siz[x]>=k) {
		for(auto a : hav[mx[x]]) {
			for(int i=1; i<k; i++) {
				res=min(res, max({f[a][i], f[x][k-i], dep[a]-dep[x], out[x]}));
			}
		}
	}
	if(!mx[x] || !sec[x]) {
		hav[x].push_back(x);
		for(auto v : e[x]) {
			if(v==fa) continue;
			for(auto a : hav[v]) {
				hav[x].push_back(v);
			}
		}
		return;
	}
	for(auto a : hav[mx[x]]) {
		for(auto b : hav[sec[x]]) {
			for(int i=1; i<k; i++) {
				res=min(res, max({f[a][i], f[b][k-i], max(dep[a], dep[b])-dep[x]+max(out[x], now)}));
			}
		}
	}
	hav[x].push_back(x);
	for(auto v : e[x]) {
		if(v==fa) continue;
		for(auto a : hav[v]) {
			hav[x].push_back(v);
		}
	}
}
void work() {
	cin>>n>>k;
	res=n;
	for(int i=1; i<=n; i++) e[i].clear(), hav[i].clear(), out[i]=0, mx[i]=sec[i]=0;
	for(int i=1; i<n; i++) {
		int u, v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[1]=0;
	dfs(1, 0);
	dfs1(1, 0);
	dfs2(1, 0);
	cout<<res<<'\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin>>c>>T;
	while(T--) work();
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
