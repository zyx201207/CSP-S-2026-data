#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
vector<int> vt[N];
int c,T,n,k,minn,ans;
int a[N],dep[N];
bool flag[N],vis[N];
void dfs1(int u)
{
	vis[u]=true;
	for(int i=0;i<vt[u].size();i++)
	{
		int v=vt[u][i];
		if(!flag[v] || vis[v])
			continue;
		dfs1(v);
	}
}
void dfs2(int u,int fa)
{
	if(flag[u])
		minn=min(minn,dep[u]);
	for(int i=0;i<vt[u].size();i++)
	{
		int v=vt[u][i];
		if(v==fa)
			continue;
		dep[v]=dep[u]+1;
		dfs2(v,u);
	}
}
void check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		vis[i]=false;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && flag[i])
		{
			dfs1(i);
			cnt++;
			if(cnt>2)
				return;
		}
	}
	int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
		{
			maxx=max(maxx,0);
			continue;
		}
		minn=1e9;
		dep[i]=0;
		dfs2(i,i);
		maxx=max(maxx,minn);
	}
	ans=min(ans,maxx);
}
void dfs(int t,int now)
{
	if(t>n && now==k)
	{
		check();
		return;
	}
	if(t>n)
		return;
	if(k-now>n-t+1)
		return;
	flag[t]=true;
	dfs(t+1,now+1);
	flag[t]=false;
	dfs(t+1,now);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			vt[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		ans=1e9;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
