#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> g[100005];
int f[100005][25],fa[100005],dep[100005];
int ans,vis[105],dis[3005][3005];
int fun(int x){
	if(fa[x]==x) return x;
	return fa[x]=fun(fa[x]);
}
void kk(){
	int u;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		u=i;
		for(auto j : g[i]){
			if(vis[j]){
				if(fun(i)!=fun(j)) fa[fun(i)]=fun(j);
			}
		}
	}int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		if(fa[i]==i) cnt++;
	}if(cnt>2) return;
	int res=0;
	for(int i=1;i<=n;i++){
		int d=1e9;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			d=min(d,dis[i][j]);
		}res=max(res,d);
	}
	ans=min(ans,res);
}
void dfs(int x,int y){
	if(y>k) return;
	if(n-x+1+y<k) return;
	if(x>n){
		kk();
	}vis[x]=1;
	dfs(x+1,y+1);
	vis[x]=0;
	dfs(x+1,y);
}
void work1(){
	ans=1e9;
	dfs(1,0);
	cout<<ans<<endl;
}void dfs1(int x,int ff){
	f[x][0]=ff;
	dep[x]=dep[ff]+1;
//	cout<<f[x][0]<<endl;
//	cout<<x<<endl;
	for(int i=1;i<=19;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}for(auto y : g[x]){
		if(!dep[y]) dfs1(y,x);
	}
}int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}return f[x][0];
}
void init(){
	dfs1(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=dep[i]+dep[j]-2*dep[lca(i,j)];
		}
	}
}void work2(){
	int m=n/2;
	if(k>=m){
		cout<<1<<endl;
		return;
	}else{
		int u=m-k+2;
		cout<<(m+2)/3+2<<endl;
		return;
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}if(n==k){
		cout<<0;
		return ;
	}if(c==13||c==14){
		work2();
		return;
	}for(int i=1;i<=n;i++) dep[i]=0;
	memset(f,0,sizeof(f));
	init();
	if(c<=6)work1();
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
