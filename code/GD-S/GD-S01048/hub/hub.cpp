#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
vector<int>e[N];
int d[N],mx[N],f=0;
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	if(e[u].size()==0){
		mx[u]=d[u];
		return ;
	}
	if(e[u].size())
	for(int i=0;i<=e[u].size();i++){
		int v=e[u][i];
		if(v==fa)continue;
		dfs(v,u);
		mx[u]=max(mx[u],mx[v]);
	}
}
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
