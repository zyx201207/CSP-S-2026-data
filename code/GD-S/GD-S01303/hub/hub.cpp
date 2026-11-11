#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k,ans=1e18;
int head[2000005],to[2000005],nxt[2000005],cnt;
bool g[1005][1005];
int ff[100005];
void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void init(int n){for(int i=1;i<=n;i++) ff[i]=i;}
int find(int x){return ff[x]==x?x:ff[x]=find(ff[x]);}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y) ff[y]=x;
}
int num[1005];
set<int>ss;
bool vis[1005];
int dis[1005][1005];
queue<int>q;
int check()
{
	init(n);
	ss.clear();
	for(int i=1;i<=n;i++)
	{
		if(num[i]==0) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(num[j]==0) continue;
			if(g[i][j]) merge(i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]==0) continue;
		ss.insert(find(i));
	}
	if(ss.size()>2) return 1e18;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i]==1) continue;
		int minn=1e18;
		for(int j=1;j<=n;j++)
		{
			if(num[j]==0) continue;
			int diss=dis[i][j];
			minn=min(minn,diss);
		}
		maxn=max(maxn,minn);
	}
	return maxn;
}
void dfs(int x,int sum)
{
	if(x==n+1)
	{
		if(sum==k) ans=min(ans,check());
		return;
	}
	if(sum>k) return;
	num[x]=1;
	dfs(x+1,sum+1);
	num[x]=0;
	dfs(x+1,sum);
}
void bfs(int s)
{
	q.push(s);
	for(int i=1;i<=n;i++) dis[s][i]=1e18,vis[i]=0;
	vis[s]=1;
	dis[s][s]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int v=to[i];
			if(dis[s][v]>dis[s][x]+1)
			{
				dis[s][v]=dis[s][x]+1;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=1e18;
		memset(head,0,sizeof head);
		memset(to,0,sizeof to);
		memset(nxt,0,sizeof nxt);
		cnt=0;
		memset(g,0,sizeof g);
		memset(num,0,sizeof num);
		memset(dis,0,sizeof dis);
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
			g[u][v]=g[v][u]=1;
		}
		for(int i=1;i<=n;i++) bfs(i);
		dfs(1,0);
		cout<<ans<<endl;
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
