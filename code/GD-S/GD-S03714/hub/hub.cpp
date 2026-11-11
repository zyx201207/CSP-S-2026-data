#include <iostream>
#include <cstring> 

using namespace std;

struct edge_t
{
	int v,next;
}edge[2000010];

int C,T,n,k,head[1000010],len,f[1000010],ans=0x7fffffff;
bool used[1000010],v[1000010];

void insert(int u,int v)
{
	edge[len].v=v;
	edge[len].next=head[u];
	head[u]=len++;
}

void cdfs(int id,int fa)
{
	v[id]=0;
	for(int i=head[id];i!=-1;i=edge[i].next)
	{
		if(edge[i].v==fa)continue;
		if(v[edge[i].v])cdfs(edge[i].v,id);
	}
}

void dfs1(int id,int fa)
{
	//cerr<<"|"<<id<<endl;
	if(used[id])f[id]=0;
	else f[id]=0x3f3f3f3f;
	for(int i=head[id];i!=-1;i=edge[i].next)
	{
		if(edge[i].v==fa)continue;
		dfs1(edge[i].v,id);
		f[id]=min(f[id],f[edge[i].v]+1);
	}
}

void dfs2(int id,int fa)
{
	for(int i=head[id];i!=-1;i=edge[i].next)
	{
		if(edge[i].v==fa)continue;
		f[edge[i].v]=min(f[edge[i].v],f[id]+1);
		dfs2(edge[i].v,id);
	}
}

void dfs(int id,int mn)
{
//	cerr<<"|"<<id<<" "<<mn<<endl;
	if(id>k)
	{
		for(int i=1;i<=n;i++)v[i]=used[i];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i])
			{
				cdfs(i,-1);
				cnt++;
			}
		}
		if(cnt>2)return;
		dfs1(1,-1);
		dfs2(1,-1);
		int tmp=0;
//		cerr<<"used:";for(int i=1;i<=n;i++)cerr<<used[i]<<" ";cerr<<endl;
//		cerr<<"f:";for(int i=1;i<=n;i++)cerr<<f[i]<<" ";cerr<<endl;
		for(int i=1;i<=n;i++)tmp=max(tmp,f[i]);
//		if(tmp==1)
//		{
//			cerr<<"|||||min f:";for(int i=1;i<=n;i++)cerr<<f[i]<<" ";cerr<<endl;
//		}
		ans=min(ans,tmp);
		return;
	}
	for(int i=mn;i<=n;i++)
	{
		used[i]=1;
		dfs(id+1,i+1);
		used[i]=0;
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		ans=0x7fffffff;
		len=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			insert(u,v);
			insert(v,u);
		}
		dfs(1,1);
		cout<<ans<<endl;
	}
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
