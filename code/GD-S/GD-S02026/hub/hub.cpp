#include<bits/stdc++.h>
using namespace std;
const int N=100;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int c,t;
int n,k;
int tmp[N];
int fa[N];
int p[N];
int ans;
int dist[N][N];
int find(int x)
{
	if(x==p[x])
	{
		return x;
	}
	return find(p[x]);
}
void dfs(int num,int lim)
{
	if(num==k)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int tmppp=1e5;
			for(int j=1;j<=k;j++)
			{
				tmppp=min(dist[i][tmp[j]],tmppp);
			}
			maxn=max(maxn,tmppp);
		}
		ans=min(ans,maxn);
		return;
	}
	for(int i=lim+1;i<=n;i++)
	{
		tmp[num+1]=i;
		dfs(num+1,i);
	}
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=in();
	t=in();
	while(t--)
	{
		memset(dist,0x3f,sizeof dist);
		n=in();
		k=in();
		for(int i=1;i<=n;i++)
		{
			dist[i][i]==0;
		}
		for(int i=1;i<=n-1;i++)
		{
			int u=in(),v=in();
			dist[u][v]=1;
			dist[v][u]=1;
		}
		for(int mid=1;mid<=n;mid++)
		{
			for(int xx=1;xx<=n;xx++)
			{
				for(int yy=1;yy<=n;yy++)
				{
					if(xx!=yy&&mid!=xx&&mid!=yy)
					{
						if(dist[xx][mid]+dist[mid][yy]<dist[xx][yy])
						{
							dist[xx][yy]=dist[xx][mid]+dist[mid][yy];
						}
					}
				}
			}
		}
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			tmp[1]=i;
			dfs(1,i);
		}
		out(ans);
		cout<<endl;
	}
	return 0;
}

