#include<bits/stdc++.h>
using namespace std;


long long w[500005];
long long a[500005][505];
long long c[505][500005];
long long u,v;
long long l,n,m;
long long d,q;
long long mn=1e18;
int vis[505];

void dfs(int k,long long sum)
{
	for(int i=1;i<=c[k][1];i++)
	{
		if(c[k][i+1]==v)
		{
			sum+=a[v][k+1];
			mn=min(mn,sum);
			return ;
		}
	}
	for(int i=1;i<=c[k][1];i++)
	{
		for(int j=1;j<=a[i][1];j++)
		{
			if(vis[j+1]==0&&a[i][j+1]!=0)
			{
				dfs(j+1,sum+a[i][j+1]+a[i][k+1]);
				vis[j+1]=1;
			}
		}
	}
	return ;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>l>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		c[i][1]=k;
		for(int j=1;j<=k;j++) 
		{
			int x,y;
			cin>>x>>y;
			a[x][1]++;
			a[x][i+1]=y;
			c[i][j+1]=x;
		}
	}
	while(q--)
	{
		cin>>u>>v;
		long long sum=w[u]+w[v];
		long long mnn=1e18;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=c[i][1];j++)
				if(c[i][j+1]==u)
				{
					memset(vis,0,sizeof(vis));
					dfs(i,0);
					break;
				}
			mnn=min(mn+sum,mnn);
		}
		cout<<mnn<<endl;
	}
	return 0;
}
