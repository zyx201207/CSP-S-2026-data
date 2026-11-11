#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N=305;

int testid,AAA;
int n,m;
vector<int>e[N];
int dis[N][N];
vector<int>tmp[N][N];
int dp[N][N],dp2[N][N];
int son[N];

void dfs(int u,int f,int fb)
{
	// printf("dfs(%d,%d,%d)\n",u,f,fb);
	son[u]=1;
	dp[u][0]=0;
	dp[u][1]=0;
	for (int v:e[u])
	{
		if (v==f||v==fb)continue;
		dfs(v,u,fb);
			// printf("dp[%d][%d]=%d\n",v,0,dp[v][0]);
		for (int j=0;j<=min(son[v],m);j++)
		{
			for (int k=1;k<=min(son[u],m)&&j+k<=m;k++)
			{
				dp2[u][j+k]=min(max(dp[v][j],dp[u][k]),dp2[u][j+k]);
				// printf("dp[%d][%d]:%d\n",v,j,dp[v][j]);
				// printf("dp2[%d][%d]:%d+%d\n",u,j+k,dp[v][j],dp[u][k]);
			}
		}
		dp2[u][0]=max(dp[u][0],dp[v][0]);
		son[u]+=son[v];
		for (int k=0;k<=min(son[u],m);k++)
		{
			dp[u][k]=dp2[u][k];
		}
		for (int k=0;k<=min(son[u],m);k++)
			dp2[u][k]=1e9;
	}
	dp[u][0]++;
}
void dfs2(int u,int st)
{
	for (int v:e[u])
	{
		if (v==st||dis[st][v])continue;
		dis[st][v]=dis[st][u]+1;
		dfs2(v,st);
	}
}

int count(int x)
{
	return (x+1>>1);
}
int ddd[N];
void dfs3(int u,int w,int f,int f1,int f2)
{
	ddd[u]=min(ddd[u],w);
	for (int v:e[u])
	{
		if (v==f||v==f1||v==f2)continue;
		dfs3(v,w+1,u,f1,f2);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&testid,&AAA);
	while (AAA--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			e[i].clear();
		for (int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans=1e9;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=0;
		for (int i=1;i<=n;i++)
		{
			dfs2(i,i);
		}
		// for (int i=1;i<=n;i++)
		// 	for (int j=1;j<=n;j++)
		// 		printf("dis[%d][%d]=%d\n",i,j,dis[i][j]);
		for (int i=1;i<=n;i++)
		{
			memset(dp,0x3f,sizeof dp);
			memset(dp2,0x3f,sizeof dp2);
			// printf("LLLL\n");
			dfs(i,0,0);
			ans=min(ans,dp[i][min(son[i],m)]);
			// printf("ans:%d\n",ans);
			// return 0;
		}
				
		for (int i=1;i<=n;i++)
		{
			for (int v:e[i])
			{
				memset(dp,0x3f,sizeof dp);
				memset(dp2,0x3f,sizeof dp2);
				// printf("LLLL\n");
				dfs(i,0,v);
				for (int j=0;j<m;j++)
				{
					tmp[i][v].push_back(dp[i][j]);
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				int mn=1e9,iv=0,jv=0;
				for (int v:e[i])
				{
					if (dis[v][j]<mn)
						mn=dis[v][j],iv=v;
				}
				mn=1e9;
				for (int v:e[j])
				{
					if (dis[v][i]<mn)
						mn=dis[v][i],jv=v;
				}
				mn=1e9;
				for (int k=1;k<m;k++)
				{
					// if (max(tmp[i][iv][k],tmp[j][jv][m-k])==1)
					// 	printf("%d %d(%d):%d,%d\n",i,j,k,tmp[i][iv][k],tmp[j][jv][m-k]);
					mn=min(mn,max(tmp[i][iv][k],tmp[j][jv][m-k]));
				}
				for (int i=1;i<=n;i++)
					ddd[i]=1e9;
				dfs3(iv,1,0,i,j);
				dfs3(jv,1,0,i,j);
				int fff=0;
				for (int i=1;i<=n;i++)
					if (ddd[i]<1e9)
						fff=max(fff,ddd[i]);
				// printf("%d %d:%d,%d\n",i,j,mn,fff);
				ans=min(ans,max(mn,fff));
			}
		}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++)
			for (int v:e[i])
				tmp[i][v].clear();
	}
	return 0;
}
/*

*/