#include<bits/stdc++.h>
using namespace std;
int id,ne[1000005],to[1000005],head[1000005];
int n,k;
void add(int x,int y)
{
	id++;
	to[id]=y;
	ne[id]=head[x];
	head[x]=id;
}
int dis[1000005];
void dfs(int x,int fa)
{
	dis[x]=dis[fa]+1;
	for(int i=head[x];i;i=ne[i])
	{
		if(to[i]!=fa)
		{
			dfs(to[i],x);
		}
	}
}
void init(int n)
{
	dis[0]=0;
	id=0;
	for(int i=1;i<=n;i++)
	{
		head[i]=0;
	}
}
void solve2()
{
	dis[0]=-1;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	int maxi=0;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>dis[maxi])
		{
			maxi=i;
		}
	}
	dfs(maxi,0);
	maxi=0;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>dis[maxi])
		{
			maxi=i;
		}
	}
	if(k==n)
	{
		cout<<0<<"\n";
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<dis[i]<<' ';
//	}
//	cout<<"\n";
	cout<<max((dis[maxi]-k+2+3)/4,1)<<"\n";
	init(n);
}
int dis2[1005][1005];
void dfs2(int x,int fa,int yx)
{
	dis2[yx][x]=dis2[yx][fa]+1;
	for(int i=head[x];i;i=ne[i])
	{
		if(to[i]!=fa)
		{
			dfs2(to[i],x,yx);
		}
	}
}
int bans=1000;
int vis[105];
void init100()
{
	bans=1000;
	id=0;
	for(int i=1;i<=100;i++)
	{
		head[i]=0;
		vis[i]=0;
	}
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			dis2[i][j]=0;
		}
	}
}
void gone()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int nans=n;
			for(int j=1;j<=n;j++)
			{
				if(vis[j])
				nans=min(nans,dis2[i][j]);
			}
			ans=max(ans,nans);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<vis[i];
	}
	bans=min(ans,bans);
}
void dfsdfs(int x,int y)
{
	if(x==n)
	{
		if(y==k)
		{
			gone();
		}
		return;
	}
	vis[x+1]=0;
	dfsdfs(x+1,y);
	vis[x+1]=1;
	dfsdfs(x+1,y+1);
	vis[x+1]=0;
}
void solve100()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		dis2[i][0]=-1;
		dfs2(i,0,i);
	}
	bans=1000;
	dfsdfs(0,0);
	cout<<bans<<"\n";
	init100();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		if(false)
		{
			solve100();
		}
		else
		{
			solve2();
		}
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
