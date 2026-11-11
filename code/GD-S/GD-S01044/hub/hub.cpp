#include <bits/stdc++.h> 
using namespace std;
using ll =long long;
const int N=100;
int n,k,dep[N],fa[N];
const ll inf=1e18+10;
vector<int> g[N];
bool vis[N];
void dfs(int x){
	for(int v:g[x]){
		if(v==fa[x])continue;
		fa[v]=x;
		dep[v]=dep[x]+1;
		dfs(v);
	} 
}
int lca(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y])swap(x,y);
		x=fa[x];
	}return x;
}
int dist(int x,int y){
	return dep[lca(x,y)]*2-dep[x]-dep[y];
} 
struct Uni{
	int f[N];
	void init(){
		for(int i=1;i<=n;i++)if(vis[i])f[i] =i;
	} int find(int x){
		return f[x]==x?f[x]:f[x]=find(f[x]);
	} 
	bool chk(){
		int cnt=0;
		for(int i=1;i<=n;i++)if(vis[i]){
			if(find(i)==i)cnt++;
		}return cnt<=2;
	}
	void  merge(int x,int y){
		f[find(x)]=find(y);
	}
}uni;struct Edge{
	int u,v;
}e[N];
ll ans=LLONG_MAX;
void search(int x,int cnt){
	if(cnt>k)return;
	if(x==n+1){
		uni.init();
		for(int i=1;i<n;i++){
			if(vis[e[i].u]&&vis[e[i].v])uni.merge(e[i].u,e[i].v);
		}
		if(uni.chk()){
			ll tans=0;
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				for(int j=1;j<=n;j++){
					if(!vis[j])continue;
					tans+=dist(i,j);
				}
			}
			ans=min(tans,ans);
		}
		return ;
	}
	if(cnt==k) search(x+1,cnt);
	else{
		for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			search(x+1,cnt+1);
			vis[i]=0;
		}
	} 
	search(x+1,cnt);
	}
	
}


void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
		e[i].u=x,e[i].v=y;
	}
	fa[1]=0;
	dep[1]=1;
	dfs(1);
	ans=LLONG_MAX;
	search(1,0);
	cout<<-ans<<"\n";
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
