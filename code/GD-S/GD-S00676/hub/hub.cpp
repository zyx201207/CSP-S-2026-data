#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int N=2e6+20,inf=1e18;
int tid;
int n,k;
vector<int> p[N];
bool vis[N];
bool bz[N];
void dfs(int x)
{
	if(!bz[x])return;
	if(vis[x])return;
	vis[x]=1;
	for(int i:p[x])dfs(i);
}
int dep[N],g[N],dp[N];
void dfs1(int x,int fa)
{
	g[x]=dp[x]=0;
	for(int i:p[x])
	{
		if(i==fa)continue;
		dep[i]=dep[x]+1;
		dfs1(i,x);
		g[x]=max(g[x],g[i]+1);
		dp[x]=max(dp[x],dp[i]);
	}
	int mx=0;
	for(int i:p[x])
	{
		dp[x]=max(dp[x],g[i]+mx+2);
		mx=max(mx,g[i]);
	}
}
void solve()
{
	cin>>n>>k;
	fo(i,1,n)p[i].clear();
	fo(i,1,n-1)
	{
		int u,v;cin>>u>>v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	if(tid==13||tid==14)
	{
		if(k==n)cout<<0<<endl;
		else if(k>=n/2)cout<<1<<endl;
		else
		{
			int m=n/2,ans=2;
			while(k+(ans-1)*4<m)ans++;
			cout<<ans<<endl;
		}
	}
	if(tid<=3)
	{
		int f[20][20];
		fo(i,1,n)fo(j,1,n)f[i][j]=inf;
		fo(i,1,n)for(int j:p[i])f[i][j]=1;
		fo(i,1,n)f[i][i]=0;
		fo(t,1,n)
			fo(i,1,n)
				fo(j,1,n)
					f[i][j]=min(f[i][j],f[i][t]+f[t][j]);
		int ans=inf;
		fo(s,0,(1<<n)-1)
		{
			vector<int> v;
			fo(i,1,n)bz[i]=0;
			fo(i,1,n)
				if(s&(1<<(i-1)))
					v.push_back(i),bz[i]=1;
			if((int)v.size()!=k)continue;
			fo(i,1,n)vis[i]=0;
			int tot=0;
			fo(i,1, n)
				if(bz[i]&&!vis[i])
					dfs(i),tot++;
			if(tot>2)continue;
			int res=0;
			fo(i,1,n)
			{
				int d=inf;
				for(auto j:v)d=min(d,f[i][j]);
				res=max(res,d);
			}
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
	if(tid==7||tid==11||tid==12)
	{
		dfs1(1,1);
		int len=dp[1]+1;
		int ans=1;
		while(ans*4+2<=len)ans++;
		cout<<ans<<endl;
	}
}
signed main()
{
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>tid>>T;
	while(T--)solve();
	return 0;
}
