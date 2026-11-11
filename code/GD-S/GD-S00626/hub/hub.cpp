#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
#define fi first
#define se second
#define chkmin(x,y) (x=min(x,y))
#define chkmax(x,y) (x=max(x,y))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
const int N=1e6+5;
const int K=21;
int n,k,u,v,fa[N][K],par[N],dep[N];
bool tag[N];
vector<int> G[N];
void dfs(int u,int par){
	dep[u]=dep[par]+1,fa[u][0]=par;
	for(int i=1;i<=20;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:G[u]){
		if(v==par) continue;
		dfs(v,u);	
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;--i)
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;--i)
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline int dist(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
} 
inline int find(int x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	par[fx]=fy;
}
void solve(){
	read(n),read(k);
	for(int i=1;i<=n;++i) G[i].clear();
	bool sub=(n&1);
	int m=(n-1>>1);
	for(int i=1;i<n;++i){
		read(u),read(v);
		sub&=(i<=m&&u==i&&v==i+1||i>m&&u==i-m&&v==i+1);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1,0);
	if(n<=20){
		int s=(1<<n),ans=n+1;
		for(int i=0;i<s;++i){
			int cnt=0;
			for(int j=1;j<=n;++j) par[j]=j,tag[j]=false;
			for(int j=1;j<=n;++j) 
				if(i>>j-1&1) tag[j]=true,++cnt;
			if(cnt>k) continue;
			for(int j=1;j<=n;++j){
				if(!tag[j]) continue;
				for(int v:G[j])
					if(tag[v]) merge(j,v);
			}
			cnt=0;
			for(int j=1;j<=n;++j)
				if(tag[j]&&par[j]==j) ++cnt;
			if(cnt>2) continue;
			int ret=0;
			for(int j=1;j<=n;++j){
				int dis=n+1;
				for(int k=1;k<=n;++k){
					if(!tag[k]) continue;
					chkmin(dis,dist(j,k));
				}
				chkmax(ret,dis);
			}	
			chkmin(ans,ret);
		}
		write(ans);
		putchar('\n');
	}
	else if(sub){
		int m=(n-1>>1);
		if(n==k) puts("0");
		else if(k>=m) puts("1"); 
		else write((m-k+7)/4),putchar('\n');	
	}
	else{
		int s=1;
		for(int i=2;i<=n;++i)
			if(dist(1,i)>dist(1,s)) s=i;
		int t=1;
		for(int i=2;i<=n;++i)
			if(dist(s,i)>dist(s,t)) t=i;
		int m=dist(s,t);
		if(k==n) puts("0");
		else write(m/2),putchar('\n');
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=1,T=1;
	read(c),read(T);
	while(T--) solve();
	return 0;
} 
