#include <bits/stdc++.h>
using namespace std; const int N = 105;
int c,t,n,k,d[N],tmp[N]; vector <int> e[N]; bool is[N];
void dfs(int u,int fa) {
	for (int v:e[u]) if (v != fa)
		tmp[v] = tmp[u]+1,dfs(v,u);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) {
		scanf("%d%d",&n,&k);
		for (int i = 1,u,v;i < n;i++) {
			scanf("%d%d",&u,&v);
			e[u].push_back(v),e[v].push_back(u);
		}
		int ans = n;
		for (int i = 0;i < (1<<n);i++)
			if (__builtin_popcount(i) == k) {
				int cur = 0,scc = k;
				for (int j = 1;j <= n;j++) d[j] = 1e9;
				for (int j = 0;j < n;j++) {
					is[j+1] = (i>>j)&1;
					if (!is[j+1]) continue;
					for (int k = 1;k <= n;k++) tmp[k] = 0;
					dfs(j+1,0);
					for (int k = 1;k <= n;k++)
						d[k] = min(d[k],tmp[k]);
				}
				for (int j = 1;j <= n;j++)
					cur = max(cur,d[j]);
				for (int j = 1;j <= n;j++) for (int k:e[j])
					scc -= is[j]&&is[k]&&j<k;
				if (scc <= 2) ans = min(ans,cur);
			}
		printf("%d\n",ans);
		for (int i = 1;i <= n;i++) e[i].clear();
	}
	return 0;
}
