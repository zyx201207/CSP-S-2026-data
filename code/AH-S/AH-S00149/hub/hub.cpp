#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,u,v,mn,b[1000005],vis[1000005],dp[15][15];
vector <int> a[2000005];
void work(int p){
	vis[p]=1;
	for(int i=0; i<a[p].size(); i++)
		if(!vis[a[p][i]])
			work(a[p][i]);
}
bool ok(){
	for(int i=1; i<=m; i++)
		vis[i]=0;
	int s=0;
	for(int i=1; i<=m; i++)
		if(!vis[b[i]])
		{
			work(b[i]);
			s++;
			if(s>2)
				return 0;
		}
	return 1;
}
void get2(int p,int fa,int s){
	vis[p]=1;
	dp[p][fa]=min(dp[p][fa],s);
	for(int i=0; i<a[p].size(); i++)
		if(!vis[a[p][i]])
			get2(a[p][i],fa,s+1);
}
int get(){
	int y=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			dp[i][j]=1e9;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			vis[j]=0;
		get2(i,i,0);
	}
	for(int i=1; i<=n; i++)
	{
		int x=1e9;
		for(int j=1; j<=m; j++)
		{
			if(i==b[j])
			{
				x=1e9;
				break;
			}
			x=min(x,dp[i][b[j]]);
		}
		if(x==1e9) continue;
		y=max(y,x);
	}
	return y;
}
void dfs(int p,int s){
	if(m-s>n-p+1) return;
	if(p==n+1)
	{
		if(ok())
			mn=min(mn,get());
		return;
	}
	dfs(p+1,s);
	if(s<m)
	{
		b[s+1]=p;
		dfs(p+1,s+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--)
	{
		mn=1e18;
		cin>>n>>m;
		for(int i=1; i<n; i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0);
		cout<<mn<<"\n";
	}
	return 0;
}
