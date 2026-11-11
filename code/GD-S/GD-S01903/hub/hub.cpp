#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+5;
int c,T;
vector<int> edge[N];
int uu[N],vv[N],n,k;
bool vis[N];
int maxx;
void dfs(int u,int fa,int dep){
	maxx=max(maxx,dep);
	for(int v:edge[u])if(v!=fa && !vis[v])dfs(v,u,dep+1);
}
int check(){
	maxx=0;
	for(int i=1;i<=n;i++)if(vis[i])dfs(i,0,0);
	return maxx;
}
int dis[N],fat[N];
void dfs2(int u,int fa){
	dis[u]=dis[fa]+1;fat[u]=fa;
	for(int v:edge[u])if(v!=fa)dfs2(v,u);
}
int stk[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)edge[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		uu[i]=u,vv[i]=v;
	}
	if(c<=3){
		int res=1e18;
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=1;j<=n;j++)if(i>>(j-1)&1)cnt++;
			if(cnt!=k)continue;
			int b=0;
			for(int j=1;j<n;j++)if((i>>(uu[j]-1)&1) && (i>>(vv[j]-1)&1))b++;
			if(b!=k-2)continue;
			for(int j=1;j<=n;j++)vis[j]=i>>(j-1)&1;
			res=min(res,check());
		}
		cout<<res<<endl;
		return;
	}
	else if(c==13 || c==14){
		int z=(n+1)/2;
		if(k==n){
			cout<<0<<endl;
			return;
		}
		if(k>=z){
			cout<<1<<endl;
			return;
		}
		cout<<(z-k+2)/4+1<<endl;
		return;
	}
	dfs2(1,0);
	int id=1;
	for(int i=2;i<=n;i++)if(dis[id]<dis[i])id=i;
	dfs2(id,0);
	int di=1;
	for(int i=2;i<=n;i++)if(dis[di]<dis[i])di=i;
	int top=0;
	for(int x=di;x!=id;x=fat[x])stk[++top]=x;
	k=min(k,top);
	for(int i=(top-k+2)/4+1,j=1;j<=k/2;i++,j++)vis[stk[i]]=true;
	for(int i=top-(top-k+1)/4,j=1;j<=k-k/2;i--,j++)vis[stk[i]]=true;
	cout<<check()<<endl;
	for(int i=1;i<=n;i++)vis[i]=false;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--)solve();
}
