#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
vector<int> mp[N];
int fa[N],sd[N],siz[N],son[N];
void dfs(int u){
	siz[u]=1;
	for(int v:mp[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		sd[v]=sd[u]+1;
		dfs(v);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
}
int top[N];
void dfs2(int u,int tip){
	top[u]=tip;
	if(son[u])dfs2(son[u],tip);
	for(int v:mp[u]){
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(sd[top[u]]<sd[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return sd[u]<sd[v]?u:v;
}
int dis(int u,int v){
	int zu=lca(u,v);
	return sd[u]+sd[v]-sd[zu]-sd[zu];
}
bitset<31> choo,vis;
void dfs3(int u){
	vis[u]=1;
	for(int v:mp[u])if(choo[v]&&vis[v]==0)dfs3(v);
}
void sol(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		mp[i].clear();
		fa[i]=sd[i]=siz[i]=son[i]=0;
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	dfs2(1,1);
	int ans=0x3f3f3f3f;
	for(int s=0;s<=(1<<n)-1;s++){
		int num=0;
		choo=0;
		for(int i=1;i<=n;i++){
			if(s>>(i-1)&1){
				num++;
				choo[i]=1;
			}
		}
		if(num!=k)continue;
		vis=0;
		num=0;
		for(int i=1;i<=n;i++){
			if((s>>(i-1)&1)&&vis[i]==0){
				dfs3(i);
				num++;
			}
		}
		if(num>2)continue;
		int t=0;
		for(int i=1;i<=n;i++){
			int t1=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(s>>(j-1)&1){
					t1=min(t1,dis(i,j));
				}
			}
			t=max(t,t1);
		}
		ans=min(ans,t);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("hub2.in","r",stdin);
//	freopen("dma.out","w",stdout);
	int ceshi,t;
	cin>>ceshi>>t;
	while(t--){
		sol();
	}
	return 0; 
}
/*

*/
