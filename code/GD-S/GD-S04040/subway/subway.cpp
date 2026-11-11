#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int s[100005];
int head[100005],to[100005],nxt[100005],W[100005],tot;
int dis[100005],vis[100005];
struct Node{
	int num,v;
	bool operator < (const Node& a) const
	{
		return v>a.v;
	}
};
void add(int u,int v,int w)
{
	tot++;
	nxt[tot]=head[u];
	to[tot]=v;
	W[tot]=w;
	head[u]=tot;
}
int query(int u,int v)
{
	for(int i=1;i<=m+n;i++)
		dis[i]=1e9,vis[i]=0;
	priority_queue <Node> q;
	q.push({u,0});
	vis[u]=1,dis[u]=0;
	while(!q.empty())
	{
		Node k=q.top();
		q.pop();
		//cout<<k.num<<" "<<k.v<<"\n";
		if(k.num==v)
			return k.v;
		vis[k.num]=1;
		if(k.v^dis[k.num]) continue;
		for(int i=head[k.num];i;i=nxt[i])
		{
			if(dis[to[i]]>dis[k.num]+W[i]&&!vis[to[i]])
			{
				dis[to[i]]=dis[k.num]+W[i];
				q.push({to[i],dis[to[i]]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		scanf(" %d",&s[i]);
	for(int i=1,k=0;i<=n;i++)
	{
		scanf(" %d",&k);
		for(int j=1,u,w;j<=k;j++)
		{
			scanf(" %d %d",&u,&w);
			add(u,m+i,w);
			add(m+i,u,w);
		}
	}
	for(int i=1,u,v,z;i<=q;i++)
	{
		scanf(" %d %d",&u,&v);
		z=query(u,v);
		printf("%d\n",s[u]+s[v]+z);
	} 
	return 0;
} 
