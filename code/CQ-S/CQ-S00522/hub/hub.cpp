#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 1000005;
	int head[MAXN], CNT;
	struct edge{
		int next, to;
	}ed[MAXN << 1];
	void add_edge(int u, int v){
		ed[++CNT] = (edge){head[u], v};
		head[u] = CNT;
	}
	int u[MAXN], v[MAXN], is[MAXN], fa[MAXN], t[MAXN];
	int belong(int x){
		if(x == fa[x]) return x;
		return fa[x] = belong(fa[x]); 
	}
	int q[MAXN], d[MAXN];
	int main(){
		int c, T;
		scanf("%d%d", &c, &T);
		int n, k;
		while(T--){
			scanf("%d%d", &n, &k);
			for(int i = 1;i < n;i++){
				scanf("%d%d", &u[i], &v[i]);
				add_edge(u[i], v[i]);
				add_edge(v[i], u[i]);
			}
			int ans = n;
			int all = (1 << n);
			for(int s = 1;s < all;s++){
				int cn = 0;
				for(int i = 1;i <= n;i++){
					if((s >> (i - 1)) & 1){
						cn++;
						is[i] = 1;
					}
					else is[i] = 0;
					fa[i] = i;
					t[i] = d[i] = 0;
				}
				if(cn > k) continue;
				for(int i = 1;i < n;i++){
					if(is[u[i]] && is[v[i]]){
						int x = belong(u[i]), y = belong(v[i]);
						fa[x] = y;
					}
				}
				cn = 0;
				int l = 0, r = 0;
				for(int i = 1;i <= n;i++){
					if(is[i]){
						q[++r] = i;
						int tmp = belong(i);
						if(!t[tmp]){
							t[tmp] = 1;
							cn++;
						}
					}
				}
				if(cn > 2) continue;
				while(l < r){
					int u = q[++l];
					for(int i = head[u];i;i = ed[i].next){
						int v = ed[i].to;
						if(is[v] || d[v]) continue;
						d[v] = d[u] + 1;
						q[++r] = v;
					}
				}
				int now = 0;
				for(int i = 1;i <= n;i++) now = max(now, d[i]);
				ans = min(ans, now);
			}
			printf("%d\n", ans);
			//Çå¿Õ
			for(int i = 1;i <= n;i++) head[i] = 0;
			CNT = 0; 
		}
//		while(1);
		return 0;
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	return Luo_ty::main();
}
//47MB
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

0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
