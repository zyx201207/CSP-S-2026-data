#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,ans,flag[1001],vis[1001];
vector<int>a[1001];
void dfs1(int rt,int fa)
{
	for(auto i:a[rt])
	{
		if(i==fa)
		{
			continue;
		}
		if(!flag[i])
		{
			continue;
		}
		dfs1(i,rt);
		vis[i]=1;
	}
}
void dfs2(int rt,int fa)
{
	for(auto i:a[rt])
	{
		if(i==fa)
		{
			continue;
		}
		if(vis[i]<=vis[rt]+1)
		{
			continue;
		}
		vis[i]=vis[rt]+1;
		dfs2(i,rt);
	}
}
bool check()
{
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(flag[i]&&!vis[i])
		{
			vis[i]=1;
			dfs1(i,0);
			cnt++;
		}
		if(cnt==3)
		{
			return 0;
		}
	}
	return 1;
}
int solve()
{
	memset(vis,0x3f,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		if(flag[i])
		{
			vis[i]=0;
			dfs2(i,0);
		}
	}
	int res=0;
	for(int i=1;i<=n;++i)
	{
		res=max(res,vis[i]);
	}
	return res;
}
void dfs(int step,int cnt)
{
	if(step>n)
	{
		if(cnt==k&&check())
		{
			ans=min(ans,solve());
		}
		return;
	}
	if(cnt==k&&check())
	{
		for(int i=step;i<=n;++i)
		{
			flag[i]=0;
		}
		ans=min(ans,solve());
		return;
	}
	flag[step]=0;
	dfs(step+1,cnt);
	flag[step]=1;
	dfs(step+1,cnt+1);
	flag[step]=0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;++i)
		{
			a[i].clear();
		}
		for(int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
