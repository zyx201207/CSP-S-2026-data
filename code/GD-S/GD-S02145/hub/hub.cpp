#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
int n,ln,k,ans;
const int N=1e6+10,L=30,M=3e3+10;
int s[N],fa[N],u[N],v[N],d[N],dep[N];
int dis[M][M],f[N][L];
bool used[N],bz[N];
vector<int> G[N];
int fnd(int x)
{
	return fa[x]==x?x:fa[x]=fnd(fa[x]);
}
void dfs(int x)
{
	if(x>k)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			bz[i]=false;
		}
		for(int i=1;i<n;i++)
			if(used[u[i]]&&used[v[i]])
			{
				int tu=fnd(u[i]),tv=fnd(v[i]);
				if(fa[tu]!=tv) fa[tu]=tv;
			}
		int cnt=0,res=0;
		for(int i=1;i<=n;i++)
			if(used[i]&&!bz[fnd(i)])
			{
				bz[fa[i]]=true;
				if((++cnt)>2) return;
			}
		for(int i=1;i<=n;i++)
		{
			d[i]=n;
			for(int j=1;j<=k;j++)
				d[i]=min(d[i],dis[i][s[j]]);
			res=max(res,d[i]);
		}
		ans=min(ans,res);
	}
	else
	{
		for(int i=s[x-1]+1;i<=n;i++)
			if(!used[i])
			{
				used[i]=true;
				s[x]=i;
				dfs(x+1);
				used[i]=false;
			}
	}
	return;
} 
void work(int c,int l)
{
	for(int d:G[c])
	{
		if(d==l) continue;
		f[d][0]=c;
		dep[d]=dep[c]+1;
		work(d,c);
	}
	return;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	if(dep[x]>dep[y])
	{
		for(int i=ln;i>=0;i--)
			if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	} 
	if(x==y) return x;
	for(int i=ln;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
void init()
{
	ln=log2(n);
	ans=n;
	dep[1]=1;
	work(1,0);
	for(int i=1;i<=ln;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int l=lca(i,j);
			dis[i][j]=dis[j][i]=dep[i]+dep[j]-(dep[l]<<1);
		}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
		}
		init();
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
