#include<iostream>
#include<vector>
#define int long long
using namespace std;
int c,t,n,k,sol[1000005],ans,dep[100005],fa[100005][30];
vector<int> g[1000005];
bool vis[1000005],in[1000005];
void dfsd(int u,int f){
	fa[u][0]=dep[u]=dep[f]+1;
	for(auto v:g[u]) if(v!=f) dfsd(v,u);
}
void init(){
	for(int p=1;p<30;p++) for(int u=1;u<=n;u++) fa[u][p]=fa[fa[u][p-1]][p-1];
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int len=y-x;
	for(int i=30;i>=0;i--) if((len>>i)&1) x=fa[x][i];
	if(x==y) return x;
	for(int i=30;i>-0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfsc(int u){
	vis[u]=1;
	for(auto v:g[u]) dfsc(v);
}
bool check(int s){
	int cnt=0;
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=s;i++) if(!vis[sol[i]]) dfsc(sol[i]),cnt++;
	return cnt<=2;
}
void dfs(int u,int f,int tot){
	sol[tot]=u;	
	if(tot==k){
		if(check(tot)){
			int res=-1;
			for(int i=1;i<=n;i++){
				if(in[i]) continue;
				for(int j=1;j<=tot;j++){
					int dis=dep[i]+dep[sol[j]]-2*lca(i,sol[j]);
					res=max(res,dis);
				}
			}
			ans=min(ans,res);
		}
		return;
	}
	for(auto v:g[u]){
		if(v==f||in[v]) continue;
		in[v]=1;
		dfs(v,u,tot+1);
		in[v]=0;
	}
}
void solve(){
	ans=2e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int u,v,i=1;i<n;i++) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	dfsd(1,0);
	init();
	for(int i=1;i<=n;i++) dfs(i,0,1); 
	cout<<ans<<'\n';
}
signed main(){
	//TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
