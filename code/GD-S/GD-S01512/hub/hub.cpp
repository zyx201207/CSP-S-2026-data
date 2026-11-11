#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){write(-x); return;}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
const int N=2e6+5;
int c,T;
int n,k;
vector<pii> e;
vector<int> g[15];
int fa[15],vis[15];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int dis[15][15];
void dfs(int u,int fa,int rt){
	for(auto v:g[u]){
		if(v==fa) continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs(v,u,rt);
	}
}
void solve(){
	n=read(); k=read();
	for(int i=1;i<=n;i++) g[i].clear();
	e.clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		e.push_back({u,v});
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> tmp;
	int ans=1e18;
	for(int i=1;i<=n;i++) dfs(i,0,i);
	for(int st=0;st<(1<<n);st++){
		tmp.clear();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			if((1<<(i-1))&st) tmp.push_back(i),vis[i]=1;
		}
		if(tmp.size()!=k) continue;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(auto p:e){
			if(vis[p.fi]&&vis[p.se]){
				int x=find(p.fi),y=find(p.se);
				if(x!=y) fa[x]=y;
			} 
		}
		int cnt=0;
		for(auto i:tmp) cnt+=(find(i)==i);
		if(cnt!=2) continue;
		int res=0;
		for(int i=1;i<=n;i++){
			int d=1e18;
			for(auto j:tmp) d=min(d,dis[i][j]);
			res=max(res,d);
		}
		ans=min(ans,res);
	}
	write(ans); puts("");
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(); T=read();
	while(T--) solve();
	return 0;
}

