#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
vector<int>g[1010];
const int inf=1e9+7;
bitset<1010>vis,isleaf;
int lt[1010],dep[1010],fa[1010],x;
void dfs(int u,int f){
	bool flg=1;fa[u]=f;
	for(auto v:g[u])if(v!=f){
		dfs(v,u);
		if(dep[v]+1>=dep[u])dep[u]=dep[v]+1;
		if(dep[u]>=x)lt[u]+=lt[v];
	}++lt[u];
}
void dfs2(int u,int f,int d){
	if(vis[u])return;
	vis[u]=1;
	if(d==x)return;
	for(auto v:g[u])if(v!=f)dfs2(v,u,d+1);
}
void dfs3(int u,int f){
	if(vis[u])return;
	bool flg=0;
	for(auto v:g[u])if(v!=f)dfs3(v,u),flg=1;
	if(flg==0)isleaf[u]=1;
}
signed main(){
	fre("hub");
	cin.tie(0)->sync_with_stdio(0);
	int c,T;cin>>c>>T;
	while(T--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1,u,v;i<n;++i)cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		if(n==k){cout<<"0\n";continue;}
		int l=1,r=(n-1)/2;
		while(l<r){
			memset(lt,0,sizeof(lt));
			x=l+r>>1,dfs(1,1);
			int res=lt[1];
			for(int i=2;i<=n;++i){
				vis.reset();
				dfs2(fa[i],i,0);
				dfs2(i,fa[i],-inf);
				for(int j=1;j<=n;++j)if(!vis[i]){
					isleaf.reset();
					dfs3(j,j);
					for(int k=1;k<=n;++k)if(isleaf[k])dfs2(k,k,0);
					for(int k=1;k<=n;++k)res+=!vis[k];
					break;
				}
			}
			if(res<=k)r=x;
			else l=x+1;
		}
		cout<<l<<'\n';
		x=1,dfs(1,1);
	}
	return 0;
}//18:29