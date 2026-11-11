#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> g[100005];
int ans=-0x3f3f3f3f;
int dep[100005],fa[100005][23];
int p[110];
bool vis[110];
void dd(int u){
	vis[u]=1;
	for(int v:g[u]){
		if(p[v]&&!vis[v]){
			dd(v);
		}
	}
}
bool check(int tn){
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=tn;i++){
		if(p[i]){
			dd(i);
			cnt++;
			if(cnt>2) return 0;
		}
	}
	return (cnt<=2);
}
void dfss(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=21;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:g[u]){
		if(!dep[v]) dfss(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=21;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=21;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){
	if(p[x]&&p[y]) return 0;
	return (dep[x]+dep[y]-2*dep[lca(x,y)]);
}
vector<int> li;
int dmx(int tn){
	int d=0x3f3f3f3f;
	for(int i=1;i<=tn;i++){
		for(int j:li){
			d=min(dis(i,j),d);
		}
	}
	return d;
}
void dfs(int i,bool num,int cho){
	p[i]=num;
	if(cho>k) return ;
	if(i+(n-i)<cho) return ;
	if(i==n||cho==k){
		if(i==n&&cho!=k) return ;
		if(check(i)){
			for(int j=1;j<=i;j++) if(p[j]) li.push_back(j);
			ans=max(ans,dmx(i));
		}
		return ;
	}
	dfs(i+1,0,cho);
	dfs(i+1,1,cho+1);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=-0x3f3f3f3f;
		dfss(1,0);
		dfs(0,0,0);
		if(ans==-0x3f3f3f3f) ans=0;
		cout<<ans<<'\n';
	}
	return 0;
}
