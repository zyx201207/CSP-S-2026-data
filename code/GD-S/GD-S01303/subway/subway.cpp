#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int a[500005];
int head[1500005],to[1500005],nxt[1500005],w[1500005],cnt;
int dis[1500005];
bool vis[1500005];
int lstans[100005];
struct que{
	int x;
	int y;
	int id;
}query[100005];
void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
bool cmp(que s,que t)
{
	return s.x<t.x;
}
struct node{
	int pos;
	int di;
	bool operator<(const node &x)const
	{
		return x.di<di;
	}
};
priority_queue<node>pq;
void dij(int s)
{
	for(int i=1;i<=n+m;i++) dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty())
	{
		node t=pq.top();
		pq.pop();
		int x=t.pos;
		if(vis[x]) continue;
		for(int i=head[x];i;i=nxt[i])
		{
			int v=to[i];
			if(dis[v]>dis[x]+w[i])
			{
				dis[v]=dis[x]+w[i];
				if(!vis[v]) pq.push({v,dis[v]});
			}
		}
	}
}
struct nodee{
	int x;
	int step;
};
queue<nodee>qu;
int bfs(int s,int t)
{
	while(!qu.empty()) qu.pop();
	for(int i=1;i<=n+m;i++) dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	vis[s]=1;
	qu.push({s,0});
	while(!qu.empty())
	{
		nodee tt=qu.front();
		qu.pop();
		if(tt.x==t)
		{
			return tt.step;
		}
		int x=tt.x;
		for(int i=head[x];i;i=nxt[i])
		{
			int v=to[i];
			if(!vis[v])
			{
				vis[v]=1;
				qu.push({v,tt.step+w[i]});
			}
		}
	}
	return 0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,w;
			cin>>x>>w;
			add(m+i,x,w);
			add(x,m+i,w);
		}
	}
	if(c>=12&&c<=15)
	{
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)+a[x]+a[y]<<endl;
			//记得加上端点的 
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cin>>query[i].x>>query[i].y;
			query[i].id=i;
			if(query[i].x>query[i].y) swap(query[i].x,query[i].y);
		}
		sort(query+1,query+q+1,cmp);
		int lst=0;
		for(int i=1;i<=q;i++)
		{
			int x=query[i].x,y=query[i].y;
			if(x==lst)
			{
				lstans[query[i].id]=dis[y]+a[x]+a[y];
				continue;
			}
			dij(x);
			lstans[query[i].id]=dis[y]+a[x]+a[y];
			lst=x;
		}
		for(int i=1;i<=q;i++) cout<<lstans[i]<<endl;
		return 0;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
