#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=1e6+5;
int c,n,m,d,q,tt;
int a[N][N],mm[M],t[N][N],k[N],dis[N][N],gh[M];
bool vis[3][M];
vector<int> s[N];
struct Venti
{
	int v,w;// 到达站台，时间
};
vector<Venti> g[M];
struct Windy
{
	int val,id;
}b1[N],b2[N],b3[N];

bool cmp(Windy x,Windy y)
{
	return x.val<y.val; 
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>mm[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			tt=t[i][j];
		}
		for(int u=1;u<=k[i];u++)
		{
			for(int v=u+1;v<=k[i];v++)
			{
				g[a[i][u]].push_back({a[i][v],t[i][u]+t[i][v]});
				g[a[i][v]].push_back({a[i][u],t[i][u]+t[i][v]});
			}
		}
	}
	if(c<=19)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==j) dis[i][j]=0;
				else dis[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int u=1;u<=k[i];u++)
			{
				for(int v=u+1;v<=k[i];v++)
				{
					int uu=a[i][u],vv=a[i][v];
					dis[uu][vv]=min(dis[uu][vv],t[i][u]+t[i][v]);
					dis[vv][uu]=min(dis[vv][uu],t[i][u]+t[i][v]);
				}
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(dis[i][k] && dis[k][j])
						dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				}
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<mm[x]+mm[y]+dis[x][y]<<endl;
		}
	}
	else if(c<=21)
	{
		int cnt=0;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				vis[i][a[i][j]]=1;
				if(i==1)
				{
				//	b1[j].id=a[i][j];
				//	b1[j].val=t[i][j];
				//	gh[a[i][j]]=t[i][j];
				}
				else 
				{
				//	b2[j].id=a[i][j];
				//	b2[j].val=t[i][j];
					if(vis[1][a[i][j]])
					{
						cnt++;
						b3[cnt].id=a[i][j];
						b3[cnt].val=t[i][j]+gh[a[i][j]];
					}
				}
			}
		}
		sort(b3+1,b3+cnt+1,cmp);
		while(q--)
		{
			int x,y,ans=0x3f3f3f3f;
			cin>>x>>y;
			if(vis[1][x] && vis[1][y])
			{
				ans=min(ans,a[1][x]+a[1][y]);
				if(b3[1].id!=x && b3[1].id!=y)
				{
					ans=min(ans,a[1][x]+b3[1].val+a[1][x]);
				}
				else if(b3[2].id!=x && b3[2].id!=y)
				{
					ans=min(ans,a[1][x]+b3[2].val+a[1][x]);
				}
				else
				{
					ans=min(ans,a[1][x]+b3[3].val+a[1][x]);
				}
			}
			if(vis[2][x] && vis[2][y])
			{
				ans=min(ans,a[2][x]+a[2][y]);
				if(b3[1].id!=x && b3[1].id!=y)
				{
					ans=min(ans,a[2][x]+b3[1].val+a[2][x]);
				}
				else if(b3[2].id!=x && b3[2].id!=y)
				{
					ans=min(ans,a[2][x]+b3[2].val+a[2][x]);
				}
				else
				{
					ans=min(ans,a[2][x]+b3[3].val+a[2][x]);
				}
			}
			if(vis[1][x])
			{
				if(b3[1].id!=x && b3[1].id!=y)
				{
					ans=min(ans,a[1][x]+b3[1].val+a[2][x]);
				}
				else if(b3[2].id!=x && b3[2].id!=y)
				{
					ans=min(ans,a[1][x]+b3[2].val+a[2][x]);
				}
				else
				{
					ans=min(ans,a[1][x]+b3[3].val+a[2][x]);
				}
			}
			if(vis[2][x])
			{
				if(b3[1].id!=x && b3[1].id!=y)
				{
					ans=min(ans,a[2][x]+b3[1].val+a[1][x]);
				}
				else if(b3[2].id!=x && b3[2].id!=y)
				{
					ans=min(ans,a[2][x]+b3[2].val+a[1][x]);
				}
				else
				{
					ans=min(ans,a[2][x]+b3[3].val+a[1][x]);
				}
			}
			cout<<mm[x]+ans+mm[y]<<endl;
		}
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
