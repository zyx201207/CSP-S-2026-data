#include<bits/stdc++.h>

using namespace std;
const int N=2e5+7;
vector<int> g[N];
#define pb emplace_back
int n,k;
int dep[N],f[N][20];
void dfs(int u,int fa){
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;i--) if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
int dist(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
int cnt(int x){
	int ans=0;
	while(x) ans+=x&1,x>>=1;
	return ans;
}
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return;
	fa[u]=v;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear(),fa[i]=i;
	for(int i=1;i<=n;i++) for(int j=0;j<20;j++) f[i][j]=0;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}dfs(1,0);
	int res=0x3f3f3f3f;
	for(int i=0;i<(1<<n);i++){
		if(cnt(i)!=k) continue;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=n;j++){
			if((i>>j-1)&1){
				if(f[j][0] && (i>>f[j][0]-1)&1) merge(j,f[j][0]);
				for(int v:g[j]) if((i>>v-1)&1) merge(j,v);
			}
		}
		int tot=0;
		for(int j=1;j<=n;j++) if(find(j)==j && ((i>>j-1)&1)) tot++;
		if(tot>2) continue;
		int ans=0;
		for(int j=1;j<=n;j++){
			int tmp=0x3f3f3f3f;
			for(int k=1;k<=n;k++)
				if((i>>k-1)&1)
					tmp=min(tmp,dist(j,k));	
			ans=max(ans,tmp);
		}
		res=min(res,ans);
	}cout<<res<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,T;cin>>C>>T;
	while(T--) solve(); 
}
/*
0 1
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
