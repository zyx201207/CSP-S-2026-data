#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n, k;
int head[N], nxt[N<<1], to[N<<1], tot=0;
bool flag[N];int ans=0x3f3f3f3f;
int fa[N][23], dep[N];
int tool[N];
void add(int u, int v){
	tot++;
	nxt[tot]=head[u];
	head[u]=tot;
	to[tot]=v;
}
void dfs(int x, int f){
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int j=1;j<=20;j++)
		fa[x][j]=fa[fa[x][j-1]][j-1];
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v, x);
	}
}
int lca(int x, int y){
	if(dep[x]<dep[y]) swap(x, y);
	for(int j=20;j>=0;j--)
		if(dep[fa[x][j]]>=dep[y])
			x=fa[x][j];
	if(x==y) return x;
	for(int j=20;j>=0;j--)
		if(fa[x][j]!=fa[y][j])
			x=fa[x][j], y=fa[y][j];
	return fa[x][0];
}
bool get(int x, int y){
	if(dep[x]<dep[y]) swap(x, y);
	while(dep[x]>dep[y]){
		x=fa[x][0];
		if(!flag[x]) return 1;
	}
	while(x!=y){
		x=fa[x][0], y=fa[y][0];
		if(!flag[x] || !flag[y]) return 1;
	}
	return 0;
}
int calc(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(flag[i]) continue;
		int res=0x3f3f3f3f;
		for(int j=1;j<=k;j++)
			res=min(res, dep[i]+dep[tool[j]]-dep[lca(i, tool[j])]*2);
		ans=max(ans, res);
	}
	return ans;
}
void dfs1(int x, int lst){
	if(x==k+1){
		ans=min(ans, calc());
		return;
	}
	for(int i=lst+1;i<=n;i++)
		if(!flag[i])
			flag[i]=1, tool[x]=i, dfs1(x+1, i), flag[i]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	 freopen("hub.in", "r", stdin);
	 freopen("hub.out", "w", stdout);
	int C, T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) head[i]=0;
		tot=0;
		for(int i=1;i<n;i++){
			int u, v;
			cin>>u>>v;
			add(u, v);
			add(v, u);
		}
		dfs(1, 0);
		ans=0x3f3f3f3f;
		dfs1(1, 0);
		cout<<ans<<endl;
	}
	return 0;
}