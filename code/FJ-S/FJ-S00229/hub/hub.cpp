#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,lst=1e9,ans[N],vis[N],dep[N],sum[N];
vector<int> G[N];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	if(!vis[u]) sum[u]+=dep[u];
	for(auto v:G[u]) if(v!=f) dfs(v,u);
}
void solve(int x,int cnt){
	if(x>n){
		int now=0;
		for(int i=1;i<=cnt;i++)
			vis[ans[i]]=1;
		dep[0]=-1;
		for(int i=1;i<=cnt;i++)
			dfs(ans[i],0);
		for(int i=1;i<=n;i++) 
			now=max(now,sum[i]);
		lst=min(lst,now);
		return ;
	}
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		solve(0,0);
		cout<<"0\n";
	}
}
