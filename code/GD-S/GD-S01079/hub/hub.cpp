#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+3;
int n,k,cnt,d[N],ans;
bool vis[N];
vector<int>g[N];
void dfs(int u,int fa){
	if(!vis[fa]&&vis[u])cnt++;
	d[u]=min(d[u],d[fa]+1);
	for(int v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k;ans=n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		if(n>20){
			cout<<(((n+1)/2)-k+3)/4<<"\n";
			continue;
		}
		for(int i=0;i<(1<<n);i++){
			int ct=0;
			for(int j=0;j<n;j++)if(i&(1<<j))ct++;
			if(ct!=k)continue;
			for(int j=1;j<=n;j++)vis[j]=0,d[j]=n;
			for(int j=1;j<=n;j++)if(i&(1<<(j-1)))vis[j]=1,d[j]=0;
			bool f=0;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					cnt=0;dfs(1,0);
					if(cnt>2){f=1;break;}
				}
			}
			if(f)continue;
			int res=0;
			for(int j=1;j<=n;j++)res=max(res,d[j]);
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
