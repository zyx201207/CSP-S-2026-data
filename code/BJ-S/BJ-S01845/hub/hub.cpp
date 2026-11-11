#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
int c,t,n,k,f[N][20],dep[N],fs[N];
vector<int> e[N],ss;
bool gg[16][16];
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i=1;(1<<i)<=n;i++) {
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i=19;i>=0;--i) {
		if(dep[f[x][i]] >= dep[y]) {
			x = f[x][i];
		}
	}
	if(x == y) return y;
	for(int i=19;i>=0;--i) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y) {
	return dep[x] + dep[y] - 2*dep[lca(x,y)];
}
int _find(int x) {
	return (x==fs[x])?fs[x]:fs[x]=_find(fs[x]);
}
void mg(int x,int y) {
	x = _find(x),y = _find(y);
	if(x == y) return;
	fs[x] = y;
	return;
}
void slv() {
	cin >> n >> k;
	for(int i=1;i<=n;i++) e[i].clear();	
	memset(gg,0,sizeof(gg));
	for(int i=1;i<n;i++) {
		int x,y;
		cin >>x >>y;
		gg[x][y]=1;gg[y][x] = 1;
		e[x].pb(y);e[y].pb(x);
	}
	dfs(1,0);
	if(c <= 3) {
		int ret = 1e9;
		for(int i=0;i<(1<<n);i++) {
			if(__builtin_popcount(i) != k) continue;
			ss.clear();
			for(int j=0;j<n;j++) {
				if(i&(1<<j)) {
					ss.push_back(j+1);
				}
			}
			for(int j=1;j<=n;j++) fs[j] = j;
			for(int xa : ss) {
				for(int xb:ss){
					if(xa == xb) continue;
					if(gg[xa][xb] == 1) mg(xa,xb);
				}
			}	
			int ccc=0;
			for(int xa : ss) {
				if(_find(xa) == xa) ccc++; 
			}
			if(ccc>2) continue;
			int now = 0;
			for(int j=1;j<=n;j++) {
				int kk = 1e9;
				for(int k : ss) {
					kk = min(kk,dis(j,k));
				}
				now = max(now,kk);
			}
			ret = min(ret,now);
		}
		cout << ret << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t ;
	while(t--) slv();
}