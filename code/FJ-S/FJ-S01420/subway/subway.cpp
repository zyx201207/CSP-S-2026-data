#include<bits/stdc++.h>
using namespace std;
const int N=5;
const int M=5e5+10;
int n,m,d,q;
long long w[M];
int a[N][M];
long long t[N][M];
int k[N];
long long ans;
int vis[M];
int g[M][N];
int s[M];
long long minn=0;
void solve1(int x,int y)
{
	minn=1e18;
	for(int i=1;i<=m;i++)
	{
		if(i==x||i==y) continue;
		if(s[i]==2)
		{
			minn=min(t[1][i]+t[2][i],minn);
		}
	}
	ans=1e18;
	if(s[x]==1&&s[y]==1&&g[x][1]==g[y][1]) ans=w[x]+w[y]+t[g[x][1]][x]+t[g[y][1]][y];
	else if(s[x]==1&&s[y]==1&&g[x][1]!=g[y][1])ans=w[x]+w[y]+t[g[x][1]][x]+t[g[y][1]][y]+minn;
	else if(s[x]==2&&s[y]==2) ans=w[x]+w[y]+min(min(t[1][x]+t[1][y],t[2][x]+t[2][y]),min(t[1][x]+t[2][y],t[2][x]+t[1][y])+minn);
	else if(s[x]==1&&s[y]==2)
	{
		if(g[x][1]==1)
		{
			ans=min(ans,w[x]+w[y]+t[1][x]+minn+t[2][y]);
			ans=min(ans,w[x]+w[y]+t[1][x]+t[1][y]);
		}
		else
		{
			ans=min(ans,w[x]+w[y]+t[2][x]+minn+t[1][y]);	
			ans=min(ans,w[x]+w[y]+t[2][x]+t[2][y]);
		}
	}
	else
	{
		if(g[y][1]==1)
		{
			ans=min(ans,w[x]+w[y]+t[1][y]+minn+t[2][x]);
			ans=min(ans,w[x]+w[y]+t[1][y]+t[1][x]);
		}
		else
		{
			ans=min(ans,w[x]+w[y]+t[2][y]+minn+t[1][x]);	
			ans=min(ans,w[x]+w[y]+t[2][y]+t[2][x]);
		}
	}
	printf("%lld\n",ans);
	ans=0,minn=0;
}
long long f[1010][1010];
void solve2(int x,int y)
{
	ans=f[x][y]+w[x]+w[y];
	printf("%lld\n",ans);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%d",&c);
	scanf("%d %d %d %d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d",&a[i][j]);
			++s[a[i][j]];
			g[a[i][j]][s[a[i][j]]]=i;
			scanf("%lld",&t[i][a[i][j]]);
		}
	}
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++) f[i][j]=1e18;
		}
		for(int i=1;i<=n;i++)
		{
			int u=a[i][1],v=a[i][2];
			f[u][v]=t[i][u]+t[i][v];
			f[v][u]=f[u][v];
		}
		for(int e=1;e<=m;e++)
		{
			for(int h=1;h<=m;h++)
			{
				for(int t=1;t<=m;t++)
				{
					f[h][t]=min(f[h][e]+f[e][t],f[h][t]);
				}
			}
		}
	}
	for(int r=1;r<=q;r++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(c==20||c==21) solve1(x,y);
		else if(c>=7&&c<=11) solve2(x,y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}