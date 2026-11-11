#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> g[1000005];
int dep[1000005],fa[100005][20];
bool ok[1000005];
int okcnt;
void dfss(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for (int j=1;j<=19;j++)fa[u][j]=fa[fa[u][j-1]][j-1];
	for (auto&v:g[u]){
		if (v==f)continue;
		dfss(v,u);
	}
}
int lca(int u,int v){
	if (dep[u]<dep[v])swap(u,v);
	for (int j=19;j>=0;j--)if (dep[u]-(1<<j)>=dep[v])u=fa[u][j];
	if (u==v)return u;
	for (int j=19;j>=0;j--)if (fa[u][j]!=fa[v][j])u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
int dis(int u,int v){
	int lc=lca(u,v);
	return dep[u]-dep[lc]+dep[v]-dep[lc];
}
int bcz[100005];
int find(int x){
	return bcz[x]==x?x:bcz[x]=find(bcz[x]);
}
void init(){
	for (int i=1;i<=n;i++)bcz[i]=i;
}
void add(int u,int v){
	u=find(u),v=find(v);
	if (u!=v)bcz[v]=u;
}
bool check1(){
	set<int> se;
	init();
	for (int i=1;i<=n;i++){
		if (!ok[i])continue;
		for (auto&j:g[i]){
			if (ok[j])add(i,j);
		}
	}
	for (int i=1;i<=n;i++)if (ok[i])se.insert(find(i));
	return se.size()<=2;
}
int check2(){
	int res=0;
	for (int u=1;u<=n;u++){
		int mi=n;
		for (int v=1;v<=n;v++){
			if (ok[v])mi=min(mi,dis(u,v));
		}
		res=max(res,mi);
	}
	return res;
}
int ans=1e9;
void dfs(int i){
	if (n+1-i<k-okcnt)return;
	if (i==n+1){
		if (okcnt==k&&check1()){
			ans=min(ans,check2());
		}
		return;
	}
	if (okcnt!=k){
		okcnt++;
		ok[i]=1;
		dfs(i+1);
		ok[i]=0;
		okcnt--;
	}
	dfs(i+1);
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for (int i=1;i<=n;i++)g[i].clear();
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	dfss(1,0);
	dfs(1);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	int _c,t;
	cin>>_c>>t;
	while(t--)solve();
	return 0;
}
