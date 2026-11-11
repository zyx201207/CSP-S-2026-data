#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,__,n,k,ans,vis[1000006];
vector<int> e[1000006];
void dfs(int u,int s){
	if(!((s>>u-1)&1)) return;
	vis[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(!vis[v]) dfs(v,s);
	}
}
int dfs2(int u,int s,int fa=0){
	if(((s>>u-1)&1)) return 0;
	int ans=1e9;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		ans=min(ans,dfs2(v,s,u)+1);
	}
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_>>__;
	while(__--){
		cin>>n>>k,ans=1e9;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v),e[v].push_back(u);
		}
		if(k==2){
			for(int ii=1;ii<=n;ii++) for(int jj=ii+1;jj<=n;jj++){
				int i=(1<<ii-1)|(1<<jj-1);
				int cnt=0;
				vis[ii]=vis[jj]=1;
				for(int j=1;j<=n;j++) cnt=max(cnt,dfs2(j,i));
				ans=min(ans,cnt);
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=0;i<(1<<n);i++){
				int cnt=0;
				for(int j=1;j<=n;j++){
					if((i>>j-1)&1) cnt++;
					if(cnt>k) break;
					vis[j]=0;
				}
				if(cnt!=k) continue;
				cnt=0;
				for(int j=1;j<=n;j++){
					if((i>>j-1)&1){
						if(!vis[j]) dfs(j,i),cnt++;
					}
				}
				if(cnt>2) continue;
				cnt=0;
				for(int j=1;j<=n;j++) cnt=max(cnt,dfs2(j,i));
				ans=min(ans,cnt);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}//hub 20pts
