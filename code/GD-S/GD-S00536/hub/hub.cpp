//code by ElderFour
//problem:hub
#include<bits/stdc++.h>
using namespace std;
const long long N=1000010,INF=1e18;
long long T,cnt,deep[N],p[N][22],head[N],answer;
long long f[N],k,n,c;
void init()
{
	for(int i=1;i<=n;i++)f[i]=i;
	return;
}
long long get(long long x)
{
	if(f[x]==x)return x;
	else return f[x]=get(f[x]);	
} 
void merge(long long x,long long y)
{
	long long fx=get(x),fy=get(y);
	if(fx!=fy)
	{
		f[fx]=fy;
		return;
	}
	return;
}
struct Edge
{
	long long u;
	long long nxt;
	long long v;
}edge[N<<1];
bool flag[N];
void add_edge(long long u,long long v)
{
	cnt++;
	edge[cnt].u=u;
	edge[cnt].nxt=head[u];
	edge[cnt].v=v;
	head[u]=cnt;
	return;
}
void DFS(long long x,long long fa)
{
	deep[x]=deep[fa]+1;
	p[x][0]=fa;
	for(int i=1;(1<<i)<deep[x];i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].nxt)
	{
		long long v=edge[i].v;
		if(v!=fa)
		{
			DFS(v,x);	
		}
	}
	return;
}
long long LCA(long long x,long long y)
{
	if(deep[x]<deep[y])swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(deep[x]-(1ll<<i)>=deep[y])
		{
			x=p[x][i];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--)
	{
		if(deep[x]-(1ll<<i)>=1&&p[x][i]!=p[y][i])
		{
			x=p[x][i];
			y=p[y][i];
		}
	}
	return p[x][0];
}
long long getdis(long long x,long long y)
{
	return deep[x]+deep[y]-2*deep[LCA(x,y)];
}
long long check(long long node)
{
	for(int i=1;i<=n;i++)
	{
		if((1ll<<(i-1))&node)flag[i]=1;
		else flag[i]=0;
	}
	init();
	long long tmp=0;
	for(int i=1;i<=n;i++)tmp+=flag[i];
	if(tmp!=k)return INF;
	for(int i=1;i<=cnt;i++)
	{
		if(flag[edge[i].u]&&flag[edge[i].v])
		{
//			cout<<edge[i].u<<' '<<edge[i].v<<'\n';
			merge(edge[i].u,edge[i].v);
		}
	}/*
	for(int i=1;i<=n;i++)cout<<flag[i];
	cout<<'\n';
	for(int i=1;i<=n;i++)cout<<f[i];
	cout<<'\n';*/
	long long one=-1,two=-1;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])continue;
		f[i]=get(i);
		if(one==-1)one=f[i];
		else if(one!=f[i])
		{
			if(two==-1)two=f[i];
			else if(two!=f[i])
			{
				return INF;
			}
		}
	}
	long long maxx=0,minn=INF;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		minn=INF;
		for(int j=1;j<=n;j++)
		{
			if(!flag[j])continue;
			minn=min(minn,getdis(i,j));
		}
		maxx=max(maxx,minn);
	}
	return maxx;
}
void cl()
{
	for(int i=1;i<=n;i++)head[i]=0;
	for(int i=1;i<=cnt;i++)edge[i].u=edge[i].v=edge[i].nxt=0;
	cnt=0;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		answer=INF;
		cin>>n>>k;
		cl();
		for(int i=1;i<n;i++)
		{
			long long u,v;
			cin>>u>>v;
			add_edge(u,v);
			add_edge(v,u); 
		}
		DFS(1,0);
		for(int i=0;i<(1ll<<n);i++)
		{
			answer=min(answer,check(i));
		}
		cout<<answer<<'\n';
	}
	return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/
