#include<bits/stdc++.h>
#define int long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=2e6+10,inf=1e18;
struct Edge{
	int u,v;
}edge[N];
int head[N],edge_size,n,C,T,u,v,l,r,k,ans,cnt;
void add(int u,int v){
	edge[++edge_size]=Edge{head[u],v};
	head[u]=edge_size;
}
int maxn[N],minn[N],c[N],dp[N],depth[N],sz[N],son[N],delta[N],kill[N];
void dfs1(int x,int f,int k){
//	cout<<x<<' '<<f<<' '<<k<<'\n';
	maxn[x]=-inf,minn[x]=inf,c[x]=0,dp[x]=0,depth[x]=0,sz[x]=0,son[x]=0,delta[x]=0;
	depth[x]=depth[f]+1;
	for(int i=head[x];i;i=edge[i].u ){
		int y=edge[i].v ;
		if(y==f)continue;
		dfs1(y,x,k);
		minn[x]=min(minn[x],minn[y]+1);
		sz[x]+=sz[y];
	}
	if(minn[x]>k)maxn[x]=0;
	for(int i=head[x];i;i=edge[i].u ){
		int y=edge[i].v ;
		if(y==f)continue;
		if(minn[x]+maxn[y]+1>k)maxn[x]=max(maxn[x],maxn[y]+1);
	}
	if(maxn[x]+1>k||(f==0&&maxn[x]!=-inf))c[x]=1,maxn[x]=-inf,minn[x]=0,sz[x]++;
	if(!sz[x])return ;
	dp[x]=1;
	for(int i=head[x];i;i=edge[i].u ){
		int y=edge[i].v ;
		if(y==f)continue;
		dp[x]+=dp[y];
		delta[x]=max(delta[x],delta[y]);
	}
	if(c[x]){
		son[x]=x;
		for(int i=head[x];i;i=edge[i].u ){
			int y=edge[i].v;
			if(y==f)continue;
			delta[x]=max(delta[x],depth[son[y]]-depth[y]);
		}
		kill[x]=delta[x];
	}else{
		int kill_count=0;
		for(int i=head[x];i;i=edge[i].u ){
			int y=edge[i].v ;
			if(y==f)continue;
			if(!son[y])continue;
			delta[x]=max(delta[x],depth[son[y]]-depth[y]);
			kill_count++;
			if(son[x])son[x]=x;
			else son[x]=son[y];
		}
		kill[x]=delta[x];
		if(kill_count==2){
			kill_count=0;
			for(int i=head[x];i;i=edge[i].u ){
				int y=edge[i].v ;
				if(y==f)continue;
				if(!son[y])continue;
				kill_count+=depth[son[y]]-depth[y];
			}
			kill[x]=max(kill[x],kill_count);
		}
	}
} 
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)head[i]=0;
	edge_size=0;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
//	cout<<edge_size<<'\n';
	l=0,r=n+1,ans=n;
	while(l<=r){
		int mid=l+r>>1;
		dfs1(1,0,mid);
//		cout<<mid<<'\n';
//		for(int i=1;i<=n;i++)cout<<c[i]<<' ';cout<<'\n';
//		for(int i=1;i<=n;i++)cout<<dp[i]<<' ';cout<<'\n';
//		for(int i=1;i<=n;i++)cout<<delta[i]<<' ';cout<<'\n';
//		for(int i=1;i<=n;i++)cout<<son[i]<<' ';cout<<'\n';
//		for(int i=1;i<=n;i++)cout<<depth[i]<<' ';cout<<'\n';
		if(dp[son[1]]-kill[son[1]]<=k)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#if LOCAL 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#endif
	cin>>C>>T;
	while(T--)solve();
}
