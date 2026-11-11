#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,d,q,w[N],a[505][N],k[N],c[N],t[505][N],x,y,dis[505][505],vis[505][505];
void dfs(int x,int sl,int ss,int tt,int sum)
{
	if(x==tt)
	{
		dis[ss][tt]=min(dis[ss][tt],sum);
		return;
	}
	for(int i=1;i<=k[sl];i++)
	{
		if(i%2==1&&!vis[a[sl][i]][sl])
		{
			vis[a[sl][i]][sl]=1;
			dfs(a[sl][i],sl,ss,tt,sum);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i==sl)
		{
			continue;
		}
		for(int j=1;j<=k[i];j++)
		{
			if(j%2==1&&!vis[a[i][j]][i]&&a[i][j]==x)
			{
				vis[a[i][j]][i]=1;
				for(int kk=1;kk<=k[sl];kk++)
				{
					if(i%2==1&&!vis[a[sl][kk]][sl]==x)
					{
						dfs(x,i,ss,tt,sum+t[i][j+1]+t[sl][kk+1]);
						break;
					}
				}
			}			
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,127,sizeof(dis));
	cin>>n>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			if(j%2==1)
			{
				cin>>a[i][j];	
			}
			else
			{
				cin>>t[i][j];
			}			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			memset(vis,0,sizeof(vis));
			for(int kk=1;kk<=m;kk++)
			{
				for(int l=1;l<=k[kk];l++)
				{
					if(a[kk][l]==i)
					{
						dfs(i,l,i,j,w[i]+w[j]+t[kk][l]);
					}
				}
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<dis[x][y];
	}
	return 0;
}
