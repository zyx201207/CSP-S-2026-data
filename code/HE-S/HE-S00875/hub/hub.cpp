#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> to[400005];
int deep[400005];
int jump[400005][21];
int lca(int x,int y)
{
	if(deep[y]>deep[x]) swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(jump[x][i]!=0&&deep[jump[x][i]]>=deep[y]) x=jump[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	{
		if(jump[x][i]!=0&&jump[y][i]!=0&&jump[y][i]!=jump[x][i])
		{
			x=jump[x][i];
			y=jump[y][i];
		}
	}
	return jump[x][0];
}
int dfs(int u,int fat)
{
	deep[u]=deep[fat]+1;
	jump[u][0]=fat;
	for(int i=1;i<=20;i++)
	{
		jump[u][i]=jump[jump[u][i-1]][i-1];
	}
	for(int v:to[u])
	{
		if(v==fat) continue;
		dfs(v,u);
	}
}
vector<int> num;
bool benum[400005];
int ans=INT_MAX;
int n,k;
void dfs2(int x,int lian)
{
	if(lian>2) return ;
	if(x==k+1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int minn=INT_MAX;
			if(benum[i]) continue;
			else
			{
				for(int j:num)
				{
					minn=min(minn,deep[i]+deep[j]-2*deep[lca(i,j)]);
				}
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return ;
	}
	for(int j=1;j<=n;j++)
	{
		if(!benum[j])
		{
			int op=1;
			for(int v:to[j])
			{
				if(benum[v]){
					op=0;break;
				}
			}
			num.push_back(j);
			benum[j]=1;
			dfs2(x+1,lian+op);
			benum[j]=0;
			num.pop_back();
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int c,t;cin>>n>>t;
	while(t--)
	{
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++) to[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dfs(1,0);
		dfs2(1,0);
		cout<<ans<<'\n';
	}
}
