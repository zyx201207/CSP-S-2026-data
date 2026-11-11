#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=1e3+10;
int n,k,fa[N][22],dep[N],ans=1e17;
vector<int> g[N],s;
bool iss[N];
void dfs(int u,int p){
	dep[u]=dep[p]+1;
	fa[u][0]=p;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==p) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
//	cout<<x<<' '<<y<<' '<<dep[x]<<' '<<dep[y]<<endl;
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
//	cout<<x<<' '<<y<<' '<<dep[x]<<' '<<dep[y]<<endl;
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
//	cout<<x<<' '<<y<<' '<<dep[x]<<' '<<dep[y]<<endl<<endl; 
	return fa[x][0];
}
bool vis[N];
void dfs3(int u,int p){
	vis[u]=true;
	for(auto v:g[u]){
		if(v==p || !iss[v]) continue;
		dfs3(v,u);
	}
}
void check(){
	int cnt=0;
	for(int i=1;i<=n;i++) vis[i]=false;
	for(auto v:s){
		if(vis[v]) continue;
		dfs3(v,0);
		cnt++;
		if(cnt>2) return;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int mn=1e17;
		for(auto v:s){
			int tmp=lca(i,v);
			mn=min(mn,dep[i]-dep[tmp]+dep[v]-dep[tmp]);
		}
		res=max(res,mn);
	}
	ans=min(ans,res);
}
void dfs2(int u,int cnt){
	if(cnt==k){check();return;}
	if(u>n) return;
	s.push_back(u);
	iss[u]=true;
	dfs2(u+1,cnt+1);
	s.pop_back();
	iss[u]=false;
	dfs2(u+1,cnt);
}
void work(){
	cin>>n>>k;
	s.clear();
	for(int i=1;i<=n;i++) g[i].clear();
	int x,y;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	ans=1e17;
	dfs2(1,0);
	cout<<ans<<endl;
}
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) work();
}
