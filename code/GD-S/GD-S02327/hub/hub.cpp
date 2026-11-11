#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,pcnt;
int asdf,T;
int p[15];
int vis[15],flag[15];
vector<int> g[15];
vector<int> points[3628805];
int b[15];
void dfs2(int x,int fa)
{
	if(flag[x]) return;
	flag[x]=1;
	for(int y:g[x])
	{
		if(y==fa) continue;
		if(!vis[y]) continue;
		dfs2(y,x);
	}
}
void dfs(int x)
{
	if(x>k)
	{
		int cnt=0;
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=k;i++)
		{
			if(flag[i]) continue;
			dfs2(i,0);
			cnt++;
		}
		if(cnt>2) return;
		else
		{
			pcnt++;
			for(int i=1;i<=k;i++)
			{
				points[pcnt].push_back(p[i]);
			}
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		p[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int bfs(int x)
{
	queue<int> q;
	q.push(x);
	int dis[15]={0};
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	while(q.size())
	{
		int u=q.front();
		if(b[u]) return dis[u];
		q.pop();
		for(int v:g[u])
		{
			if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return 0;
}
signed main()
{
	cin>>asdf>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(asdf<=3)
		{
			dfs(1);
			int aans=1e18;
			for(int i=1;i<=pcnt;i++)
			{
				memset(b,0,sizeof(b));
				cout<<"qwq\n";
				int ans=0;
				for(int j:g[i])
				{
					b[j]=1;
				}
				for(int j=1;j<=n;j++)
				{
					if(b[j]) continue;
					ans=max(ans,bfs(j));
				}
				aans=min(aans,ans);
			}
			cout<<aans<<"\n";
		}
	}
	return 0;
}
