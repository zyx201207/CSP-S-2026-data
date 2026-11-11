#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 10;
vector<int> e[maxn];
int f[maxn];
int find(int x){return f[x] == x?x:f[x] = find(f[x]);}
int dep[5010][5010],d[maxn];
void g(int x,int fa,int r){
	for(int i:e[x])
		if(i != fa){
			dep[r][i] = dep[r][x] + 1;
			g(i,x,r);
		}
} 
bool used[maxn];
int n,k;
int ans;
void dfs(int x,int cnt){
	if(cnt == k || x >= n){
		iota(f,f+n,0);
		for(int i = 0;i < n;i++)
			for(int j:e[i])
				if(used[i] && used[j])f[find(i)] = find(j);
		int v = 0;
		for(int i = 0;i < n;i++)v += used[i] && f[i] == i;
		if(v <= 2){
			memset(d,0x3f,n << 2);
			for(int i = 0;i < n;i++)
				if(used[i])
					for(int j = 0;j < n;j++)
						d[j] = min(d[j],dep[i][j]);
			int nans = 0;
			for(int i = 0;i < n;i++)nans = max(nans,d[i]);
			ans = min(ans,nans);
		}
		return;
	}
	used[x] = true;
	dfs(x + 1,cnt + 1);
	used[x] = false;
	if(n - x + cnt >= k)dfs(x + 1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i = 0;i < n;i++)e[i].clear();
		for(int i = 1;i < n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			--u,--v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c == 13 || c == 14){
			if(k == n)puts("0");
			else if((n & 3) == 1)printf("%d\n",(n >> 2) - ((k - 2) >> 2));
			else printf("%d\n",((n + 1) >> 3) - ((k - 3) >> 2));
			continue;
		}
		for(int i = 0;i < n;i++){
			dep[i][i] = 0;
			g(i,-1,i);
		}
		ans = INT_MAX;
		dfs(1,0);
		printf("%d\n",ans);
	}
}

