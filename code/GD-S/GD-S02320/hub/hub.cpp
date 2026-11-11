#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pdd;
const int N = 1e6 + 31;

int c,n,k,mid,b[N],f[N],g[N];
vector<int> edge[N];
pdd a[N];

void dfs(int x,int from){
	f[x] = 0;
	for(auto y : edge[x])
		if(y != from){
			dfs(y,x);
			if(f[y] + 1 >= mid)
				b[x]++;
			f[x] = max(f[x],f[y] + 1);
		}
}
void Dfs(int x,int from){
	int tmp = g[x];
	for(auto y : edge[x])
		if(y != from){
			g[y] = max(g[y],tmp + 1);
			tmp = max(tmp,f[y] + 1);
		}
	reverse(edge[x].begin(),edge[x].end());
	tmp = g[x];
	for(auto y : edge[x])
		if(y != from){
			g[y] = max(g[y],tmp + 1);
			if(g[y] >= mid)
				b[y]++;
			tmp = max(tmp,f[y] + 1);
			Dfs(y,x);
		}
}

bool check(int u,int v){
	for(int i = 1;i <= n;i++)
		g[i] = b[i] = 0;
	dfs(u,v); dfs(v,u);
	g[u] = g[v] = 0;
	Dfs(u,v); Dfs(v,u);
	int tmp = 0;
	for(int i = 1;i <= n;i++)
		if(b[i] > 1)
			tmp++;
	if(f[u] <= mid)
		tmp++;
	if(f[v] <= mid)
		tmp++;
	return tmp <= k;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
		edge[i].clear();
	for(int i = 1;i < n;i++){
		int u,v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		a[i] = pdd(u,v);
	}
	if(n == k){
		puts("0");
		return;
	}
	int ans = n;
	for(int i = 1;i < n;i++){
		int u = a[i].first,v = a[i].second;
		int l = 0,r = n + 1;
		while(l + 1 < r){
			mid = (l + r) >> 1;
			if(check(u,v))
				r = mid;
			else
				l = mid;
		}
		ans = min(ans,r);
	}
	printf("%d\n",ans);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t; scanf("%d%d",&c,&t);
	while(t--) solve();
}
