#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
int c,T,n,k,ans;
struct edge{
	int nxt,to;
}e[N*2];
int cnt,head[N];
inline void add(int u,int v){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
	return;
}
bool vis[N],b[N];
int dep[N],fa[N][20];
inline void dfs_(int u,int f){
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int i=1;i<20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f) continue;
		dfs_(v,u);
	}
	return;
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[x][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
inline void dfs0(int u){
	vis[u]=true;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(vis[v] || !b[v]) continue;
		dfs0(v);
	}
	return;
}
inline void dfs(int u,int tot){
//	cout<<u<<' ';
	if(tot>k) return;
	if(u==n+1){
		if(tot!=k) return;
		int t=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(b[i] && !vis[i]){
				dfs0(i);t++;
			}
		}
		if(t>2) return;
		int res=0;
		for(int i=1;i<=n;i++){
			if(!b[i]){
				int tt=1e18;
				for(int j=1;j<=n;j++){
					if(b[j]){
						int F=lca(i,j);
						tt=min(tt,dep[i]+dep[j]-2*dep[F]);
					}
				}
				res=max(res,tt);
			}
		}
		ans=min(ans,res);
		return;
	}
	b[u]=1;
	dfs(u+1,tot+1);
	b[u]=0;
	dfs(u+1,tot);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k; ans=1e18;
		cnt=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		//if(T) continue;
		dfs_(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
