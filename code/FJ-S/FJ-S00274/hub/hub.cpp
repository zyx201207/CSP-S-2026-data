#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+12,INF=1e18+2;
vector<int>g[N];
int c[N];int tot;
int df[N];
bitset<N>vis;
ll n,k;
int find(const int x){
	if(df[x]!=x)df[x]=find(df[x]);
	return df[x];
}
bool check1(){
	for(int i=1;i<=n;++i)df[i]=i;
	for(int i=1;i<=tot;++i){
		for(const int j:g[c[i]]){
			if(vis[j]){
				const int fx=find(i),fy=find(j);
				df[fx]=fy;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=tot;++i){
		if(df[i]==i)++cnt;
	} 
	return cnt<=2;
}
namespace hld{
	int fa[N],de[N],sz[N],wc[N],tp[N];
	void init(){
		fa[0]=de[0]=0;
		fill(wc+1,wc+n+1,0); 
	}
	void dfs1(const int u,const int f){
		fa[u]=f,de[u]=de[f]+1,sz[u]=1;
		for(const int v:g[u]){
			if(v==f)continue;
			dfs1(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[wc[u]])wc[u]=v;
		}
	}
	void dfs2(const int u,const int t){
		tp[u]=t;
		if(wc[u]){
			dfs2(wc[u],t);
		}
		for(const int v:g[u]){
			if(v==fa[u]||v==wc[u])continue;
			dfs2(v,v); 
		}
	}
	int lca(int x,int y){
		while(tp[x]!=tp[y]){
			if(de[tp[x]]<de[tp[y]])swap(x,y);
			x=fa[tp[x]];
		}
		if(de[x]>de[y])swap(x,y);
		return x;
	}
	ll dist(const int x,const int y){
		const int f=lca(x,y);
		if(f==x){
			return de[y]-de[x];
		}
		if(f==y){
			return de[x]-de[y];
		}
		return de[x]+de[y]-2*de[f];
	}
}using namespace hld;
void solve(){
	cin>>n>>k;
	const ll n2=(1<<n)-1;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	init();
	dfs1(1,0),dfs2(1,1); 
	//cout<<"ksks"<<lca(2,3)<<'\n';
	ll ans=INF;
	for(ll p=0;p<n2;++p){
		for(int i=1;i<=n;++i)vis[i]=0; 
		tot=0;
		for(int i=1;i<=n;++i){
			if(p&(1<<(i-1)))vis[i]=1,c[++tot]=i;
		}
		if(tot!=k)continue;

		if(check1()){
			ll mx=0;
			for(int i=1;i<=n;++i){
				if(vis[i])continue;
				ll mn=INF;
				for(int j=1;j<=tot;++j){
					mn=min(mn,dist(i,c[j]));
				}
				mx=max(mx,mn);
			}
//			cout<<mx<<':';
//			for(int i=1;i<=tot;++i){
//				cout<<c[i]<<' ';
//			}
//			cout<<'\n';
			ans=min(ans,mx);
		}
			
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
