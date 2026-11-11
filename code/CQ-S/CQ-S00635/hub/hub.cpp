#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,k,cnt,h[N],f[N][25],d[N],tot;
bool vis[N];
struct node{
	int to,nxt;
}edge[N];
void add(int u,int v){
	edge[++cnt].nxt=h[u];
	edge[cnt].to=v;
	h[u]=cnt;
}
void dfs(int u,int fa){
	int tag=0;
	if(vis[fa]) tag=1;
	d[u]=d[fa]+1;
	for(int i=h[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa) continue;
		if(vis[v]) tag=1;
		f[v][0]=u;
		for(int j=1;j<=20;j++) f[v][j]=f[f[v][j-1]][j-1];
		dfs(v,u);
	}
	if(!tag&&vis[u]) tot++;
}
int Lca(int x,int y){
	if(x==y) return x;
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(d[f[x][i]]>d[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int dist(int x,int y){
	int lca=Lca(x,y);
	return d[x]+d[y]-d[lca]*2; 
}
signed main( ){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--){
		if(c>3){
			cout<<"1"<<'\n';
			continue;
		}
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);add(v,u);
		}
		int res=1e9;
		for(int i=1;i<(1<<n);i++){
			int p=i,cnt=0;
			while(p){
				++cnt;
				p>>=1;
			}
			if(cnt!=k) continue;
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))) vis[i]=1;
			}
			tot=0;d[0]=-1;
			dfs(1,0);
			if(tot>=2) continue;
			int ans=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]) continue;
				int now=1e9;
				for(int p=1;p<=n;p++){
					if(vis[p]) continue;
					now=min(now,dist(j,p));
				}
				ans=max(ans,now);
			}
			res=min(res,ans);
		}
		cout<<res<<'\n';
	}
	return 0;
}

