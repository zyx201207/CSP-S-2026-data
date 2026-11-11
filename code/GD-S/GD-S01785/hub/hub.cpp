#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct Edge{
	int to, nxt;
}e[N+N];
int c, t, n, k, head[N], idx, d[N][N], fa[N], ans;
bool vis[N];
inline void add(int u, int v){
	e[++idx]={v,head[u]}; head[u]=idx;
}
int find(int x){
	return fa[x]==x ? x:fa[x]=find(fa[x]);
}
void dfs(int u, int fat, int st){
	for(int i=head[u],v; i; i=e[i].nxt){
		v = e[i].to;
		if(v == fat) continue;
		d[st][v] = d[st][u]+1;
		dfs(v, u, st);
	}
}
inline int check(int st){
	for(int i=1; i<=n; ++i){
		fa[i] = i;
		vis[i] = ((st>>i-1) & 1);
	}
	int cnt = k;//统计连通块数量 
	for(int u=1,l,r; u<=n; ++u){
		if(!vis[u]) continue;
		for(int j=head[u],v; j; j=e[j].nxt){
			v = e[j].to;
			if(vis[v] && find(u)!=find(v)){
				l=fa[u], r=fa[v];
				fa[l] = r;
				--cnt;
			}
		}
	}
//	printf("%d %d\n", st, cnt);
	if(cnt <= 2){
		int res=0, dis;
		for(int i=1; i<=n; ++i){
			if(vis[i]) continue;
			dis = n;
			for(int j=1; j<=n; ++j)
				if(vis[j])
					dis = min(dis,d[i][j]);
			res = max(res,dis);
		}
//		printf("%d\n", res);
		return res;
	}
	return n;
}

inline void solve(){
	scanf("%d%d", &n, &k);
	idx = 0;
	for(int i=1; i<=n; ++i) head[i] = d[i][i] = 0;
	for(int i=1,u,v; i<n; ++i){
		scanf("%d%d", &u, &v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=n; ++i) dfs(i, 0, i);

	int dis=0, st=1;
	for(int i=1; i<=n; ++i)//求树的直径 
		if(d[1][i] > d[1][st]) st = i;
	for(int i=1; i<=n; ++i)
		dis = max(dis,d[st][i]);
	if(k == 1){
		printf("%d\n", (dis+1)>>1);
	}else{
		ans = n;
		int mxst = (1<<n)-1;
		for(int i=1; i<=mxst; ++i){
			if(__builtin_popcount(i) != k) continue;
			ans = min(ans,check(i));
		}
		printf("%d\n", ans);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) solve();
	return 0;
}
