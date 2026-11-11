#include<bits/stdc++.h>
using namespace std;
int cccccc,T,dad[20005],n,use[20005],ans,vis[200005],up[200005],sd[200005],jj[200005],m,wis[];
vector<int> si[20005];
int fd(int x)
{
	if(dad[x]!=x) dad[x]=fd(dad[x]);
	return dad[x];
}
void bfs(int x,int fa)
{
	for(int i=0;i<(int)si[x].size();i++)
	{
		int vv=si[x][i];
		if(vv==fa) continue;
		up[vv]=x;
		sd[vv]=sd[x]+1;
		bfs(vv,x);
	}
	return;
}
int jl(int x,int y)
{
	if(sd[x]<sd[y]) swap(x,y);
	int sum=0;
	while(sd[x]==sd[y]) x=up[x],sum++;
	while(x==y) x=up[x],y=up[y],sum+=2;
	return sum;
}
void dfs(int x,int ls)
{
	if(x==m+1)
	{
		for(int i=1;i<=n;i++) dad[i]=i;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<(int)si[use[i]].size();j++)
			{
				if(vis[si[use[i]][j]])
				{
					dad[fd(use[i])]=fd(si[use[i]][j]);
				}
			}
		}
		int ok=0;
		for(int i=1;i<=n;i++) vis[i]=false;
		for(int i=1;i<=m;i++)
		{
			if(!vis[fd(i)]) ok++;
			vis[fd(i)]=true;
		}
		int ss=0;
		if(ok<=2)
		{
			for(int i=1;i<=n;i++)
			{
				jj[i]=2e9;
				for(int j=1;j<=m;j++)
				{
					jj[i]=min(jj[i],jl(i,use[j]));
				}
				ss=max(ss,jj[i]);
			}
		}
		ans=min(ans,ss);
		return;
	}
	if(m-x+1>n-ls+1) return;
	for(int i=ls;i<=n;i++)
	{
		use[x]=i;
		vis[i]=true;
		dfs(x,i+1);
	}
	return;
}
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) si[i].clear();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		si[x].push_back(y);
		si[y].push_back(x);
	}
	ans=2e9;
	bfs(1,0);
	dfs(1,1);
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&cccccc,&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
