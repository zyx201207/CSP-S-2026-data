#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=0x3f3f3f3f3f3f3f3fLL;
int n,k,ans=inf;
vector<int>g[1000006];
int dp[1003][1003];
bool c[1003],vis[1003];
void f(int i){
	vis[i]=1;
	for(auto v:g[i]){
		if(!vis[v]&&c[v])f(v);
	}
}
int check(){
	memset(vis,0,sizeof vis);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]&&!vis[i])f(i),cnt++;
	}
	if(cnt!=2)return 0;
	vector<int>q;
	for(int i=1;i<=n;i++)if(c[i])q.push_back(i);
	int ma=0;
	for(int i=1;i<=n;i++){
		int mi=inf;
		for(auto j:q){
			mi=min(mi,dp[i][j]);
		}
		ma=max(ma,mi);
	}
	return ma;
}
void dfs(int id,int cnt){
	if(cnt==k){
		if(int x=check())ans=min(ans,x);
		return;
	}
	if(id>n)return;
	c[id]=1;
	dfs(id+1,cnt+1);
	c[id]=0;
	dfs(id+1,cnt);
}
void oneT(){
	memset(dp,0x3f,sizeof dp);
	ans=inf;
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i]=vector<int>(),dp[i][i]=0;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		dp[u][v]=1;
		dp[v][u]=1;
	};
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
	dfs(1,0);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cout<<'a';
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	cout<<'a';
	int CCC,T;
	cin>>CCC>>T;
	while(T--){
		oneT();
	}
	return 0;
} 
