#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e3+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int c,t,n,k,s[N],d[N],f[N][31],ans;
vector<int>g[N];
int LCA(int u,int v){
	if(d[u]<d[v])swap(u,v);
	int k=d[u]-d[v];
	for(int i=31;i>=0;i--)if(k&(1<<i))u=f[u][i];
	if(u==v)return u;
	for(int i=31;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return u;
}
void dfs2(int u,int fa,int siz,bool f){
	if(siz==k){
		for(int i=1;i<=n;i++){
			if(s[i]==0)continue;
			int res=INF;
			for(int j=1;j<=n;j++){
				if(s[j]){
					res=0;
					continue;
				}
				int lca=LCA(i,j);
				int dis=d[i]+d[j]-2*d[lca];
				res=min(res,dis);
			}
			ans=max(ans,res);
		}
		return;
	}
	for(int v:g[u]){
		if(v==fa)continue;
		d[v]=d[u]+1;
		dfs2(v,u,siz,f);
	}
	s[u]=1;
	if(!s[fa]){
		if(!f)f=1;
		else return;
	}
	for(int v:g[u]){
		if(v==fa)continue;
		d[v]=d[u]+1;
		dfs2(v,u,siz+1,f);
	}
	s[u]=0;
}
void dfs1(int u,int fa){
	for(int v:g[u]){
		if(v==fa)continue;
		f[v][0]=u;
		d[v]=d[u]+1;
		dfs1(v,u);
	}
}
void init(){
	memset(s,0,sizeof s);
	memset(d,0,sizeof d);
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)g[i].clear();
	ans=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		init();
		n=read(),k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0);
		for(int i=1;i<=31;i++){
			for(int u=1;u<=n;u++){
				f[u][i]=f[f[u][i-1]][i-1];
			}
		}
		dfs2(1,0,0,0);
		write(ans),putchar('\n');
	}
}
