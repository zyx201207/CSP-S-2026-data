#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t,n,k,ans=1e18,res=1e18;
int a[N];
bool vis[N],flag[N];
vector<int>edge[N];
void check(int u,int fa)
{
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa) continue;
		if(flag[v]==1&&vis[v]==0)
		{
			vis[v]=1;
			check(v,u);
		}
	}
}
void find(int u,int fa,int dep)
{
	if(dep>res) return;
	if(flag[u]==1)
	{
		res=min(res,dep);
		return;
	}
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa) continue;
		find(v,u,dep+1);
	}
}
void dfs(int now,int num)
{
	if(num==k)
	{
		int sum=0,tot=-1e18;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) flag[i]=0;
		for(int i=1;i<=k;i++) flag[a[i]]=1;
		for(int i=1;i<=k;i++)
		{
			if(!vis[a[i]])
			{
				sum++;
				check(i,0);
			}
		}
		if(sum>2) return;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
				res=1e18;
				find(i,0,0);
				tot=max(tot,res);
			}
		}
		ans=min(ans,tot);
		return;
	}
	for(int i=now;i<=n;i++)
	{
		a[num+1]=i;
		dfs(i+1,num+1);
		a[num+1]=0;
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=1e18;
		res=1e18;
		for(int i=1;i<=n;i++) vis[i]=flag[i]=0;
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}