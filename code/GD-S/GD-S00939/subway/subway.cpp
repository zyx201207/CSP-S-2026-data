#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,K=1e3+10;
struct luk{
	int w,v;
};
vector<luk> vec[K];
int wk[N],vis[N+K];
int c,n,m,d,q,ans,sx,fx;
void dfs(int u,int t){
	vis[u]=1;
	if(u==fx){
		ans=min(ans,t);
		vis[u]=0;
		return;
	} 
	for(auto i:vec[u]){
		if(vis[i.w]) continue;
		dfs(i.w,t+i.v);
	}
	vis[u]=0;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>wk[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int w,v;
			cin>>w>>v;
			vec[m+i].push_back({w,v});
			vec[w].push_back({m+i,v});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>sx>>fx;
		ans=2e18;
		dfs(sx,0);
		cout<<ans+wk[sx]+wk[fx]<<endl;
	}
	return 0; 
} 
