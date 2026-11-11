#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int inf=2100000000;
int c,n,m,d,q,cnt,head[N],val=0,vis[N],vis2[N],w[N],a[N],l[N],r[N];
map<int,int>mp;
/*struct node
{
	int v,w;
	friend bool operator<(node a,node b)
		return a.w<b.w;
}tmp;
struct edge{
	int ne,w,to;
}e[N];
void add(int a,int b,int c)
{
	e[cnt++].to=b;
	e[cnt].w=c;
	e[cnt].ne=head[a];
	head[a]=cnt;
}
void dijiastla(int s)
{
	priority<node>q;
	for(int i=1;i<=val;i++)dis[i]=inf;
	memset(vis,0,sizeof(vis));
	vis[s]=1;dis[s]=0;
	tmp.v=s;tmp.w=0;q.push(tmp);
	while(!q.empty())
	{
		int u=q.top().v;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].ne)
		{
			int j=e[i].to;
			if(dis[j]>dis[u]+e[i].w&&!vis[j])
			{
				dis[j]=dis[u]+e[i].w;
				tmp.v=dis[j];tmp.w=j;q.push(tmp);
			}
		}
	}
	
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		for(int j=1;j<=a[i];j++)
		{
			int v[N],t[N];
			cin>>v[i]>>t[i];
			if(!vis2[v[i]])
			{
				mp[v[i]]=t[i];
				vis2[v[i]]=1;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
	//	dijiastla(l[i]);
		for(int j=1;j<=m;j++)
		cout<<w[l[i]]+w[r[i]]+mp[l[i]]+mp[r[i]]<<"\n";
	}
	return 0;
} 
