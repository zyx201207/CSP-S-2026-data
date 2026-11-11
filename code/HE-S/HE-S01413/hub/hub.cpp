#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,T,n,k,dep[N],d[N],fa[N],top[N],sz[N],bson[N];
vector<int>lk[N];
void dfs(int u,int f){
	dep[u]=dep[f]+1,sz[u]=1,fa[u]=f,d[u]=min(d[u],dep[u]);
	for(int v:lk[u]){
		if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(!bson[u]||sz[v]>sz[bson[u]])bson[u]=v;
	}
}
void hld(int u,int t){
	top[u]=t;
	if(bson[u])hld(bson[u],u);
	for(int v:lk[u]){
		if(v==bson[u]||v==fa[u])continue;
		hld(v,v);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	return y;
}
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
void sol1(){
	int ans=1e9;
		for(int s=1;s<1<<n;s++){
			if(__builtin_popcount(s)!=k)continue;
			for(int i=1;i<=n;i++)d[i]=1e9,fa[i]=i;
			for(int i=0;i<n;i++){
				if(s>>i|1){
					for(int v:lk[i+1])if(get(v)!=get(i+1))fa[get(v)]=get(i+1);
					dfs(i+1,0);
				}
			}
			set<int>st;
			for(int i=0;i<n;i++){
				if(s>>i|1)st.insert(get(i+1));
			}
			if(st.size()>2)continue;
			int mx=0;
			for(int i=1;i<=n;i++)mx=max(mx,d[i]);
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)lk[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			lk[u].push_back(v),lk[v].push_back(u);
		}
		sol1();
	}

	return 0;
}
