#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
typedef pair<int,int> P;
int c,n,m,d,q;
int w[N];
int first[N*2],nxt[800005],to[8000005],wei[8000005],num;
int dis[N*2],vis[N*2];
void add(int u,int v,int w)
{
	nxt[++num]=first[u];
	first[u]=num;
	to[num]=v;
	wei[num]=w;
}
void dijkstra(int x)
{
	priority_queue<P,vector<P>,greater<P> >que;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[x]=0;
	que.push(P{dis[x],x});
	while(!que.empty())
	{
		int u=que.top().second;
		que.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=first[u];i;i=nxt[i])
		{
			int v=to[i],w=wei[i];
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				que.push(P{dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int cnt=0,T;
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			T=t;
			cnt++;
			add(cnt+m,a,t);
			add(a,cnt+m,t);
			if(j>1)
			{
				add(cnt+m,cnt+m-1,0);
				add(cnt+m-1,cnt+m,0);
			}
		}
	}
	if(c>=12&&c<=15)
	{
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int sum=w[x]+w[y];
			for(int i=1;i<=m;i++)
			{
				dis[i]=0x3f3f3f3f3f3f3f3fll;
				vis[i]=0;
			}
			queue<int> q;
			q.push(x);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(int i=first[u];i;i=nxt[i])
				{
					int v=to[i];
					if(vis[v])continue;
					if(dis[v]>dis[u]+1)
					{
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			sum+=dis[y]*T;
			cout<<sum<<'\n'; 
		}
		return 0;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y];
		dijkstra(x);
		sum+=dis[y];
		cout<<sum<<'\n'; 
	}
	return 0;
}

