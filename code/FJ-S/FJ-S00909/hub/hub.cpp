#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,mid,fa[1000005],dp[1000005];
vector<int> e[1000005];
struct jgjg
{
	int pos,val;
}dep[1000005];
bool cmp(jgjg x,jgjg y)
{
	return x.val>y.val;
}
void dfs1(int u)
{
	for(int v:e[u])
	{
		if(v!=fa[u])
		{
			fa[v]=u;
			dep[v].pos=v;
			dep[v].val=dep[u].val+1;
			dfs1(v);
		}
	}
	return;
}
int dfsf(int u)
{
	if(dp[u]==mid)
	{
		return u;
	}
	dp[fa[u]]=dp[u]+1;
	return dfsf(fa[u]);
}
void dfs(int u,int f)
{
	if(dp[u]==0)
	{
		return;
	}
	for(int v:e[u])
	{
		if(v!=f)
		{
			dp[v]=max(dp[v],(dp[u]-1));
			dfs(v,u);
		}
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dep[1].pos=1;
		dep[1].val=1;
		fa[1]=1;
		dfs1(1);
		sort(dep+1,dep+n+1,cmp);
		int l=0,r=n;
		while(l<r)
		{
			mid=(l+r)/2;
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				dp[i]=-1;
			}
			for(int i=1;i<=n;i++)
			{
				if(dp[dep[i].pos]==-1)
				{
					sum++;
					dp[dep[i].pos]=0;
					int u=dfsf(dep[i].pos);
					dfs(u,0);
				}
			}
			if(sum<=k)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		cout<<l<<endl;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			dep[i].pos=0;
			dep[i].val=0;
			dp[i]=0;
			fa[i]=0;
		}
	}
	return 0;
}
