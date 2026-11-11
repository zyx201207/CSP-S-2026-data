#include <bits/stdc++.h>
#define re register
#define chmax(a,b) (a = max(a,b))
#define chmin(a,b) (a = min(a,b))

using namespace std;

const int N = 1e6 + 10,inf = 1e9 + 10;
int cid,T,n,m;
vector<int> g[N];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

namespace Sub1{
	int cnt,dis[N],dep[N],mxdep[N];
	
	inline void dfs1(int u){
		for (int v:g[u]){
			if (~dis[v]) continue;
			dis[v] = dis[u] + 1;
			dfs1(v);
		}
	}
	
	inline void dfs2(int u,int fa){
		dep[u] = dep[fa] + 1;
		for (int v:g[u]){
			if (v != fa) dfs2(v,u);
		}
	}
	
	inline void dfs3(int u,int y,int fa,int lim){
		mxdep[u] = ((dis[u] > lim) ? dep[u] : 0);
		for (int v:g[u]){
			if (v == fa || v == y) continue;
			dfs3(v,y,u,lim); chmax(mxdep[u],mxdep[v]);
		}
	}
	
	inline void dfs4(int u,int lim){
		mxdep[u] = ((dis[u] > lim) ? dep[u] : 0);
		for (int v:g[u]){
			if (dep[v] < dep[u]) continue;
			dfs4(v,lim); chmax(mxdep[u],mxdep[v]);
		}
	}
	
	inline void dfs5(int u,int lim){
		cnt++;
		if (cnt > m) return;
		for (int v:g[u]){
			if (dep[v] < dep[u]) continue;
			if (mxdep[v] - dep[u] > lim) dfs5(v,lim);
		}
	}
	
	inline bool check(int d,int x,int y){
		cnt = 0;
		dfs3(x,y,0,d); dfs4(y,d);
		dfs5(x,d); dfs5(y,d);
		return (cnt <= m);
	}

	inline void solve(){
		int ans = inf;
		for (re int x = 1;x <= n;x++){
			fill(dis,dis + n + 3,-1);
			int Max = 0; dfs1(x);
			for (re int i = 1;i <= n;i++) chmax(Max,dis[i]);
			chmin(ans,Max);
		}
		for (re int x = 1;x <= n;x++){
			dfs2(x,0); 
			for (re int y = 1;y <= n;y++){
				if (x == y) continue;
				fill(dis,dis + n + 3,-1);
				dis[y] = 0; dfs1(y);
				int l = 0,r = n;
				while (l < r){
					int mid = l + r >> 1;
					if (check(mid,x,y)) r = mid;
					else l = mid + 1;
				} chmin(ans,l);
			}
		} printf("%d\n",ans);
	}
}

inline void solve(){
	n = read(),m = read();
	for (re int i = 0;i <= n + 3;i++) g[i].clear();
	for (re int i = 1,a,b;i < n;i++){
		a = read(),b = read();
		g[a].push_back(b);
		g[b].push_back(a);
	}
	Sub1::solve();
//	if (n <= 100) Sub1::solve();
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid = read(),T = read();
	while (T--) solve();
	return 0;
}
