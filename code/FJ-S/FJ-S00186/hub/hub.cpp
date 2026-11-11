#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,ans;
bool w[1000011];
int fa[1000011];
vector <int> p[1000011];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

int calc(int u,int fa,int dep) {
	if (w[u])
		return dep;
	int res = 0x3f3f3f3f;
	for(int v : p[u]) {
		if (v == fa)
			continue;
		res = min(res,calc(v,u,dep + 1));
	}
	return res;
}

void dfs(int x,int tot) {
	if (tot == k) {
		int cnt = k;
		for(int i=1;i<=n;i++)
			fa[i] = i;
		for(int i=1;i<=n;i++) {
			if (!w[i])
				continue;
			for(int j : p[i]) {
				if (!w[j])
					continue;
				int u = find(i),v = find(j);
				if (u == v)
					continue;
				fa[u] = v;
				cnt--;
			}
		}
		if (cnt > 2)
			return ;
		int ma = 0;
		for(int i=1;i<=n;i++) {
			if (w[i])
				continue;
			ma = max(ma,calc(i,0,0));
		}
		ans = min(ans,ma);
		return ;
	}
	if (x == n + 1)
		return ;
	w[x] = 1;
	dfs(x + 1,tot + 1);
	w[x] = 0;
	dfs(x + 1,tot);
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) {
		ans = 0x3f3f3f3f;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			p[u].push_back(v);
			p[v].push_back(u);
		}
		dfs(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			p[i].clear();
		for(int i=1;i<=n;i++)
			w[i] = 0;
	}
	return 0;
} 
