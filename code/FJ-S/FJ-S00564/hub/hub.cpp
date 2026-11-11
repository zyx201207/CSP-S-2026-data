#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
int c,T,n,k,ans;
int a[1000006],dp[1000006]; 
vector<int>e[1000006];bool vis[1000006];
int find(int x,int cnt)
{
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]==x)return 1;
	}
	return 0;
}
void kkr(int x)
{
	if(vis[x])return;
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		dp[e[x][i]]=min(dp[e[x][i]],dp[x]+1);
		kkr(e[x][i]);
	}
}
int solve(int cnt)
{
	int max_n=0;
	for(int i=1;i<=cnt;i++)
	{
		dp[a[i]]=0;
		kkr(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		max_n=max(max_n,dp[i]);
	}
	return max_n;
}
void dfs(int num,int s)
{
	if(num==k)
	{
		ans=min(ans,solve(num));
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(num==0)
		{
			a[num+1]=i;
			dfs(num+1,s+1);
			a[num+1]=0;
		}
		else
		{
			int flag=0;
			for(int k=1;k<=num;k++)
			{
				for(int j=0;j<e[a[k]].size();j++)
				{
					if(e[a[k]][j]==i)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)break;
			}
			if(!flag&&s!=2)
			{
				a[num+1]=i;
				dfs(num+1,s+1);
				a[num+1]=0;
			} 
			else if(flag)
			{
				a[num+1]=i;
				dfs(num+1,s);
				a[num+1]=0;
			}
			else if(!flag&&s==2)
			{
				return;
			}
		} 
	}
}
signed main(void)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		memset(dp,1e16,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<e[i].size();j++)
			{
				e[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=1e16;
		dfs(0,0);
		cout<<ans<<'\n';
	}
}
