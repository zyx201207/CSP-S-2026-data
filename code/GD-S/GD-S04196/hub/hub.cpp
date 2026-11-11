#include<bits/stdc++.h>
using namespace std;

int c,T;
int n,k;
vector <int> g[2000010];
bool xuan[2000010];
bool vis[2000010];
int dis[2000010];

void dfs(int u,int fa)
{
	vis[u]=true;
	for(int v:g[u])
	{
		if(v==fa) continue;
		if(vis[v]==false&&xuan[v]==true)
			dfs(v,u);
	}
}

int dfs2(int u,int fa,int step)
{
	int maxx=step;
	if(xuan[u]==true)
		return step;
	if(step>n) return n;
	for(int v:g[u])
	{
//		cout<<"OK";
		if(v==fa) continue;
		maxx=max(dfs2(v,u,step+1),maxx);
	}
	return maxx;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	memset(vis,false,sizeof(vis));
	memset(xuan,false,sizeof(xuan));
	scanf("%d %d",&c,&T);
	while(T--)
	{
		int ans=1e9;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int mark=1<<n;
		for(int i=1;i<=mark;i++)
		{
			int m=i,t=0;
			while(m)
			{
				if(m&1) t++;
				m>>=1;
			}
			if(t!=k) continue;
			for(int j=1;j<=n;j++)
				vis[j]=xuan[j]=false,dis[j]=1e9;
			for(int j=1;j<=n;j++)
			{
				if((i&(1<<(j-1)))!=0)
				{
					xuan[j]=true;
				}
			}
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(xuan[j]==true&&vis[j]==false)
				{
					cnt++;
					dfs(j,0);
				}
			}
			if(cnt<=2&&cnt>0)
			{
//				printf("i=%d\n		",i);
				for(int j=1;j<=n;j++)
				{
					if((i&(1<<(j-1)))!=0)
					{
						dis[j]=0;
//						printf("%d ",j);
					}
				}
//				printf("\n");
				int mx=0;
				for(int j=1;j<=n;j++)
				{
//					printf("last=%d\n",mx);
					mx=max(mx,dfs2(j,0,0));
//					printf("dfs2=%d ",dfs2(j,0,0));
//					printf("%d\n",mx);
				}
//				printf("\n");
				ans=min(ans,mx);
			}
		}
		printf("%d\n",ans);
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
