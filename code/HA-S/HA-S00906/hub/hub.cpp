#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define fileio(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define mems(x,v) memset(x,v,sizeof(x))
using namespace std;
namespace BaoTx{
	using ll=long long;
	const int N=1e6+6;
	const int INF=0x3f3f3f3f;
	int hd[N],to[N*2],nxt[N*2],num=1;
	void add(int u,int v){
		num++;
		to[num]=v;
		nxt[num]=hd[u];
		hd[u]=num;
	}
	int fa[N][25],dep[N];
	void dfs(int u,int f){
		dep[u]=dep[f]+1;
		fa[u][0]=f;
		for(int i=1;i<=23;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i];
			if(v==f) continue;
			dfs(v,u);
		}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y]) swap(dep[x],dep[y]);
		for(int i=23;i>=0;i--){
			if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
		}
		if(x==y) return x;
		for(int i=23;i>=0;i--){
			if(fa[x][i]!=fa[y][i]){
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return fa[x][0];
	}
	int n,k;
	int c[N];
	int ans;
	// void slove()
	void solve(int t){
		if(t==k+1){
			int now=0;
			for(int i=1;i<=n;i++){
				int d=INF;
				for(int j=1;j<=k;j++){
					d=min(d,dep[i]+dep[c[j]]-2*dep[lca(i,c[j])]);
				}
				now=max(now,d);
			}
			ans=min(now,ans);
			return;
		}
		for(int i=c[t-1]+1;i<=n;i++){
			c[t]=i;
			solve(t+1);
		}
		c[t]=0;
	}
	void main(){
		int c,t;
		cin>>c>>t;
		while(t--){
			cin>>n>>k;
			for(int i=1;i<=n-1;i++){
				int u,v;
				cin>>u>>v;
				add(u,v);
				add(v,u);
			}
			mems(fa,0);
			mems(dep,0);
			dfs(1,0);
			ans=INF;
			solve(1);
			cout<<ans<<endl;
		}
	}
}
int main(){
	fileio(hub);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	BaoTx::main();
	return 0;
}