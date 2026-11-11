#include<bits/stdc++.h>
using namespace std;

#define N 1000001
#define INF 0x7fffffff

int c,t,dis[N];
int n,k;
bool vis[N];

vector<int>g[N];

void solve(),dfs(int,int),dfs2(int,int);
bool check(int);

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}

inline void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l=1,r=N-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
		g[i].clear();
	return;
}

inline bool check(int x){
	memset(dis,0,sizeof dis);
	memset(vis,0,sizeof vis);
	int ans=0;
	vis[1]=true;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(dis[i]<=x){
			ans++;
			dis[i]=INF;
		}
	memset(dis,0,sizeof dis);
	memset(vis,0,sizeof vis);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		if(dis[i]<=x){
			ans++;
			dis[i]=INF;
		}
	return ans>=x;
}

void dfs(int u,int deep){
	dis[u]=deep;
	for(int x:g[u])
		if(!vis[x]){
			vis[x]=true;
			dfs(x,deep+1);
		}
	return;
}

void dfs2(int u,int deep){
	dis[u]=max(dis[u],deep);
	for(int x:g[u])
		if(!vis[x]){
			vis[x]=true;
			dfs(x,deep+(dis[u]!=INF));
		}
	return;
}
