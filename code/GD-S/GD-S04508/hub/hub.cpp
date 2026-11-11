#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,ans,s;
bool vis[1000007];
vector<int> g[1000007];
void dfs(int x,int cnt,long long l,long long mx){
	if(cnt==k){
		ans=min(mx,ans);
		return;
	}
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]]==0){
			dfs(x,cnt+1,l+1,max(mx,l));
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=k;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			dfs(i,1,0,0);	
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
