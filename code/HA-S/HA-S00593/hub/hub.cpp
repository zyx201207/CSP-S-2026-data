#include<bits/stdc++.h>
using namespace std;
int c,n,k,t,u,v,dis[1000005],mindis,mmindis=0x3f,minid,vis[1000005],ans;
vector<int> a[1000005];
void dfs1(int fa,int x,int num)
{
	queue<int> q;
	q.push(x);
	vis[x]=1;
	num--;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i = 0;i<a[x].size();i++)
		{
			if(!vis[a[x][i]]&&num)
			{
				vis[a[x][i]]=1;
				num--;
				q.push(a[x][i]);
			}
		}
	}
	
}
void dfs(int fa,int x)
{	
	if(vis[x])
	{
		mindis=max(mindis,dis[x]);
		return;
	}
	mindis=max(mindis,dis[x]);
	for(int i = 0;i<a[x].size();i++)
	{
		if(a[x][i]!=fa)
		{
			dis[a[x][i]]=dis[x]+1;
			dfs(x,a[x][i]);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		for(int i = 1;i<=n;i++)
		{
			a[i].clear();
		}
		mmindis=0x3f;
		cin>>n>>k;
		for(int i = 1;i<n;i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i = 1;i<=n;i++)
		{
			mindis=0;
			memset(dis,0,sizeof(dis));
			dfs(0,i);
			if(mindis<mmindis)
			{
				mmindis=mindis;
				minid=i;
			}
		}
		mmindis=0x3f;
		for(int i = 1;i<minid;i++)
		{
			mindis=0;
			memset(dis,0,sizeof(dis));
			dfs(0,i);
			if(mindis<mmindis)
			{
				mmindis=mindis;
				ans=i;
			}
		}
		dfs1(0,ans,k/2);
		mmindis=0x3f;
		for(int i = minid+1;i<=n;i++)
		{
			mindis=0;
			memset(dis,0,sizeof(dis));
			dfs(0,i);
			if(mindis<mmindis)
			{
				mmindis=mindis;
				ans=i;
			}
		}
		dfs1(0,ans,k-k/2);
		mmindis=0x3f;
		for(int i = 1;i<=n;i++)
		{
			if(!vis[i])
			{
				memset(dis,0,sizeof(dis));
				mindis=0;
				dfs(0,i);
				mmindis=min(mindis,mmindis);
			}
		}
		cout<<mmindis<<endl;
	}
	return 0;
 } 
