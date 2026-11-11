//20·Ö 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int D=1e5+10,M=5e5+10;
int c,n,m,d,x,y;
struct node{
	int v,w;
};
vector<node> mp[M];
bool vis[M];
int e[M],o,ans;
int si[M];
void build(int n,int m,int d){
	o=m;
	for(int i=1;i<=m;i++) cin>>e[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int x1,t1,x2,t2;
		cin>>x1>>t1>>x2>>t2;
		mp[x1].push_back({++o,t1});
		mp[o].push_back({x1,t1});
		mp[x2].push_back({++o,t2});
		mp[o].push_back({x2,t2});
		mp[o-1].push_back({o,0});
		mp[o].push_back({o-1,0});
	}
}
void dfs(int u,int l){
	for(int i=0;i<mp[u].size();i++){
		if(mp[u][i].v==y){
			ans=min(ans,l+mp[u][i].w);
			return ;
		}
	}
	vis[u]=1;
	for(int i=0;i<mp[u].size();i++){
		if(mp[u][i].v>m&&vis[mp[u][i].v]) continue;
		dfs(mp[u][i].v,l+mp[u][i].w);
	}
	vis[u]=0;
}
signed main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	cin>>c>>n>>m>>d>>T;
	if(7<=c<=11){
		build(n,m,d);
		while(T--){
			memset(vis,0,sizeof(vis));
			ans=1e18;
			cin>>x>>y;
			dfs(x,0);
			cout<<ans+e[x]+e[y]<<"\n";
		}
	}
	else{
		for(int i=1;i<=m;i++) cin>>e[i];
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1;j<=k;j++){
				int x,t;cin>>x>>t;
				si[x]=min(si[x],t);
			}
		}
		while(T--){
			int x,y;
			cin>>x>>y;
			cout<<si[x]+si[y]+e[x]+e[y]<<"\n";
		}
	}

	return 0;
}

