#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
const int N=1e6+5;
vector<int>e[N];
int a[N],vis[N];
void dfs(int u){
	vis[u]=1;
	for(int v:e[u]){
		if(!vis[v]&&a[v]) dfs(v);
	}
}
int st[N][25],dep[N];
void dfs3(int u,int fa){
	dep[u]=dep[fa]+1;
	st[u][0]=fa;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int v:e[u]){
		if(v==fa) continue;
		dfs3(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[st[u][i]]<dep[v]) continue;
		u=st[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(st[u][i]==st[v][i]) continue;
		u=st[u][i],v=st[v][i];
	}
	return st[u][0];
}
int ans=1e9; 
void dfs2(int x,int cnt){
	if(x>n&&cnt==k){
		for(int i=1;i<=n;i++) vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]) dfs(i),cnt++;
			if(cnt>2) return;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]) continue;
			int val=1e9;
			for(int j=1;j<=n;j++){
				if(!a[j]) continue;
				int Lca=lca(i,j);
				val=min(val,dep[i]+dep[j]-2*dep[Lca]);
			}
			res=max(res,val); 
		}
		ans=min(ans,res);
		return;
	}
	if(x>n) return;
	if(cnt<k){
		a[x]=1,dfs2(x+1,cnt+1);
		a[x]=0,dfs2(x+1,cnt);
		return;
	}
	if(cnt==k){
		a[x]=0,dfs2(x+1,cnt);
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++) for(int j=0;j<=20;j++) st[i][j]=0;
		for(int i=1;i<=n;i++) dep[i]=0,e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs3(1,0);
		dfs2(1,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
