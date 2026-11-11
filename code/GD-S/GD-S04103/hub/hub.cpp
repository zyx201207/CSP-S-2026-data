#include<bits/stdc++.h>
const int N=1e6+5,inf=2e9;
using namespace std;
int C,T;
int n,k,a,b;
int idx=0,h[N],e[N<<1],ne[N<<1],p[N],ans=inf;
int lg[N],f[N][30],d[N];
bool vis[N],flag[N];
void add(int a,int b)
{
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=lg[d[x]];i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=h[x];i!=0;i=ne[i])
	{
		int y=e[i];
		if (y!=fa)
		{
			dfs(y,x);
		}
	}
}
int LCA(int x,int y)
{
	if (d[x]<d[y])
	{
		swap(x,y);
	}
	while(d[x]>d[y])
	{
		x=f[x][lg[d[x]-d[y]]];
	}
	if (x==y)
	{
		return x;
	}
	for(int i=lg[d[x]];i>=0;i--)
	{
		if (f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y)
{
//	printf("LCA(%d,%d)=%d\n",x,y,LCA(x,y));
	return d[x]+d[y]-2*d[LCA(x,y)];
}
void dfs2(int x)
{
	flag[x]=true;
	for(int i=h[x];i!=0;i=ne[i])
	{
		int y=e[i];
		if (!flag[y]&&vis[y])
		{
			dfs2(y);
		}
	}
}
void dfs1(int x)
{
	if (x==k)
	{
		int check=0;
		for(int i=1;i<=k;i++)
		{
			if (!flag[p[i]])
			{
				check++;
				dfs2(p[i]);
			}
		}
		fill(flag,flag+n+1,false);
		if (check>2)
		{
			return ;
		}
//		if (p[1]!=1||p[2]!=4)
//		{
//			return ;
//		}
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int minn=inf;
			for(int j=1;j<=k;j++)
			{
//				printf("%d %d %d\n",i,p[j],dis(i,p[j]));
				minn=min(minn,dis(i,p[j]));
			}
			maxn=max(maxn,minn);
		}
//		if (maxn==1)
//		{
//			for(int i=1;i<=k;i++)
//			{
//				printf("%d ",p[i]);
//			}
//			printf("\n");
//		}
//		printf("%d\n",maxn);
		ans=min(ans,maxn);
		return ;
	}
	for(int i=p[x]+1;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=true;
			p[x+1]=i;
			dfs1(x+1);
			p[x+1]=0;
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&C,&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		for(int i=2;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			add(a,b),add(b,a);
			lg[i]=lg[i>>1]+1;
		}
		dfs(1,0);
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d:%d\n",i,d[i]);
//		}
//		printf("%d %d %d",LCA(1,4),LCA(3,3),LCA(2,5));
//		continue;
		dfs1(0);
		printf("%d\n",ans);
		ans=inf;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=d[i];j++)
			{
				f[i][j]=0;
			}
		}
		fill(h,h+n+1,0);
		fill(e,e+idx+1,0);
		fill(ne,ne+idx+1,0);
		fill(p,p+n+1,0);
		fill(lg,lg+n+1,0);
		fill(d,d+n+1,0);
		fill(vis,vis+n+1,false);
		fill(flag,flag+n+1,false);
	}
	return 0;
}
