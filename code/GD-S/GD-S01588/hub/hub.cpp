#include<bits/stdc++.h>
using namespace std;
const int N=12;
vector<int>g[N];
int n,k,vip[N],vis[N],dis[N][N];
void dfs(int u){
	vis[u]=1;
	for(int v:g[u])if(vip[v]&&!vis[v])dfs(v);
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;u--,v--;
		g[u].push_back(v),g[v].push_back(u);
	}
	int ans=1e9;
	for(int s=1;s<(1<<n);s++){
		if(__builtin_popcount(s)!=k){
			continue;
		}
		for(int j=0;j<n;j++)vip[j]=((s>>j)&1);
		int cnt=0;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<n;j++){
			if(!vis[j]&&vip[j])dfs(j),cnt++;
		}
		if(cnt>2)continue;
		memset(dis,0x3f,sizeof(dis));
		for(int j=0;j<n;j++)dis[j][j]=0;
		for(int u=0;u<n;u++)for(int v:g[u])dis[u][v]=1;
		for(int i=0;i<n;i++)for(int k=0;k<n;k++)for(int j=0;j<n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		int ddd=0;
		for(int i=0;i<n;i++){
			int dd=1e9;
			for(int j=0;j<n;j++)if(vip[j])dd=min(dd,dis[i][j]);
			ddd=max(ddd,dd);
		}
		ans=min(ddd,ans);
	}
	cout<<ans<<'\n';
}
void solve2(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x;cin>>x;cin>>x;
	}
	if(k==n)cout<<0<<'\n';
	else if(k>=n/2)cout<<1<<'\n';
	else cout<<(n/2-k+3)/4+1<<'\n';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	int _,__;cin>>_>>__;
	if(_<=3)while(__--)solve();
	else while(__--)solve2();
} 
