#include <bits/stdc++.h>
using namespace std;
const int INF=1e5;
int c,t,n,k,u,v,dis[15][15],d[15],tot,ans;
bool vis[15];
vector<int> h[1000005];
void dfs1(int u,int fa,int x){
	if(u==x)dis[x][u]=0;
	else dis[x][u]=dis[x][fa]+1;
	for(int i=0;i<h[u].size();i++){
		int v=h[u][i];
		if(v==fa)continue;
		dfs1(v,u,x);
	}
}
void dfs(int u,int fa){
	if(vis[u]==1&&vis[fa]==0)tot++;
	for(int i=0;i<h[u].size();i++){
		int v=h[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
void work(int k,int lft){
	if(n-k+1<lft)return;
	if(k==n+1){
		tot=0;
		dfs(1,0);
		if(tot<=2){
			int maxx=0;
			for(int i=1;i<=n;i++){
				d[i]=INF;
				for(int j=1;j<=n;j++){
					if(vis[j])d[i]=min(d[i],dis[i][j]);
				}
				maxx=max(maxx,d[i]);
			}
			ans=min(ans,maxx);
		}
		return;
	}
	work(k+1,lft);
	if(lft!=0){
		vis[k]=1;
		work(k+1,lft-1);
		vis[k]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)h[i].clear();
		ans=INF;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			h[u].push_back(v);
			h[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			dfs1(i,-1,i);
		}
		work(1,k);
		cout<<ans<<'\n';
	}
}
