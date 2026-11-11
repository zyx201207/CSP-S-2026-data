#include<bits/stdc++.h>
#define INF 2e18
#define endl '\n'
#define int long long
#define fi first
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int N = 15;

int c,t,n,k,ans;
int vl[N],vis[N],d[N];
vector <int> g[N];
//18:02 15pts
void dfs1(int u){
	vis[u]=1;
	for(int v:g[u])if(!vis[v]&&vl[v])dfs1(v);
}
void dfs2(int u,int pre){
	for(int v:g[u])if(v!=pre)d[v]=min(d[v],d[u]+1),dfs2(v,u);
}
void dfs(int stp){
	
	if(stp==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++)vis[i]=0,d[i]=INF;
		for(int i=1;i<=n;i++)if(vl[i]==1)cnt++,d[i]=0;
		if(cnt!=k)return;
		int scc=0;
		for(int i=1;i<=n;i++)if(!vis[i]&&vl[i])dfs1(i),scc++;
		if(scc>2)return;
//		for(int i=1;i<=n;i++)cout<<vl[i]<<" ";cout<<endl;
//		for(int i=1;i<=n;i++)cout<<d[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)if(vl[i])dfs2(i,i);
		int res=0;
		for(int i=1;i<=n;i++)res=max(res,d[i]);
		ans=min(ans,res);
		return;
	} 
	vl[stp]=0,dfs(stp+1),vl[stp]=1,dfs(stp+1),vl[stp]=0;
} 
void solve(){
	for(int i=1;i<=n;i++)g[i].clear();
	cin>>n>>k,ans=n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].pb(y),g[y].pb(x);
	}
//	cout<<123123<<endl;
	dfs(1),cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>c>>t;t--;)solve();return 0;
}
