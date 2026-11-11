#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int c,t,n,k,father[maxn],dep[maxn],fa[maxn],ans=0x7f7f7f7f;
bool vis[maxn];
vector<int> edge[maxn];
void init(int u,int fa){
	dep[u]=dep[fa]+1;
	father[u]=fa;
	for(auto v : edge[u]){
		if(v==fa) continue; 
		init(v,u);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[y]<dep[x]) x=father[x];
	while(x!=y) x=father[x],y=father[y];
	return x;
}
int get(int x){return (fa[x]==x ? x : fa[x]=get(fa[x]));}
void merge(int x,int y){
	int u=get(x),v=get(y);
	if(u!=v){
		fa[u]=v;
	}
}
inline int getnum(){
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		if(!vis[i]) continue;
		for(int j=1;j<=n;++j) if(vis[j]) merge(i,j);
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		if(vis[i]&&get(i)==i) sum++;
	}
	if(sum>2) return 0x7f7f7f7f;
	int res=0;
	for(int i=1;i<=n;++i){
		int now=0x7f7f7f7f;
		if(vis[i]) continue ;
		for(int j=1;j<=n;++j) if(vis[j]&&i!=j) now=min(now,dep[i]+dep[j]-2*dep[lca(i,j)]); 
		res=max(res,now);
 	}
 	return res;
}
void dfs(int idx,int now){
	if(now==k){
		ans=min(ans,getnum());
		return ;
	}
	if(idx>n) return ;
	vis[idx]=1;
	dfs(idx+1,now+1);
	vis[idx]=0;
	dfs(idx+1,now); 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(father,0,sizeof(father));
		memset(dep,0,sizeof(dep));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<n;++i) edge[i].clear();
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			edge[u].emplace_back(v);
			edge[v].emplace_back(u);
		}
		init(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
	}
}
