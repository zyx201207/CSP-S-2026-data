#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,a[2000005];
int head[100005],to[100005],nxt[100005],cnt;
void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int dis[100005];
bool vis[100005];
int ans[100005];
queue<int>q;
void bfs(int s)
{
	q.push(s);
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	vis[s]=1;
	dis[s]=0;
	ans[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int v=to[i];
			if(dis[v]>dis[x]+1)
			{
				dis[v]=dis[x]+1;
				ans[v]=ans[x];
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
			else if(dis[v]==dis[x]+1)
			{
				ans[v]=ans[v]+ans[x];
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	int cntedge=0;
	while(t--)
	{
		cntedge=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x=a[j]-a[i];
				if(x<=d)
				{
					add(i,j);
					cntedge++;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			memset(ans,0,sizeof ans);
			bfs(i);
			for(int j=i+1;j<=n;j++) if(ans[j]==2) sum++;
		}
		cout<<sum<<endl;
		cnt=0;
		for(int i=1;i<=cntedge;i++) head[i]=nxt[i]=to[i]=0;
	}
	return 0;
}
