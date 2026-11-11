#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
const int N=1005;
int q,_,n,K,ans,fa[N][20],a[N][N],c[N],dep[N];
vector<int>e[N];
struct Tree{
	int siz,f[N];
	void init(){
		siz=n;
		for(int i=1;i<=n;++i)f[i]=i;
		return;
	}
	int find(int x){
		if(f[x]==x)return x;
		return f[x]=find(f[x]);
	}
	void merge(int u,int v){
		int fu=find(u),fv=find(v);
		if(fu==fv)return;
		f[fu]=fv;--siz; 
		return;
	} 
	int sum(){return siz;} 
}T;
void dfs(int u){
	for(auto v:e[u]){
		if(v==fa[u][0])continue;
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		dfs(v);
	}
	return;
}
void init(){
	for(int j=1;j<=19;++j)
		for(int i=1;i<=n;++i)fa[i][j]=fa[fa[i][j-1]][j-1];
	return;
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;--i)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;--i){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int ask(int u,int v){
	int g=lca(u,v);
	return dep[u]+dep[v]-dep[g]*2;
}
void solve(int k){
	if(k>K){
		T.init();
		for(int i=1;i<=K;++i)
			for(int j=1;j<K;++j)if(a[c[i]][c[j]])T.merge(c[i],c[j]);
		if(T.sum()-n+K>2)return;
		int maxn=0;
		for(int i=1;i<=n;++i){
			int minn=inf;
			for(int j=1;j<=K;++j)minn=min(minn,ask(i,c[j]));
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	for(int i=c[k-1]+1;i<=n;++i){
		c[k]=i;
		solve(k+1); 
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>q>>_;
	while(_--){
		cin>>n>>K;ans=inf;
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)a[i][j]=0;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			a[u][v]=a[v][u]=1;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		dep[1]=1;
		dfs(1);
		init();
		solve(1);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
