#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,t,n,k,u,v;
vector<int>g[N];
int b[N],vis[N],ans,vs[N];
int d[N][N];
void dfs0(int u,int fa){
	vs[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		if(!vis[v]) continue;
		dfs0(v,u);
	}
}
void check(){
	int cnt=0;
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=k;i++){
		if(!vs[b[i]]) dfs0(b[i],0),cnt++;	
	}
	if(cnt>2) return;
	int mx=-1;
	for(int i=1;i<=n;i++){
		int mi=0x3f3f3f3f;
		for(int j=1;j<=k;j++){
			mi=min(mi,d[i][b[j]]);
		}
		mx=max(mx,b[i]);
	}
	ans=min(ans,mx);
}
void dfs(int x,int step){
	if(x>step){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1,step);
		vis[i]=0;
		b[x]=0;
	}
}
void dfs1(int rt,int u,int fa){
	d[rt][u]=d[rt][fa]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		dfs1(rt,v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c >> t;
	while(t--){
		memset(d,0,sizeof(d));
		ans=0x3f3f3f3f;
		cin >> n >> k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			cin >>u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			d[i][0]=-1;
			dfs1(i,i,0);
		}
		dfs(1,k); 
		cout << ans <<endl;
	}
} 
