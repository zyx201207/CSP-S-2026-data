#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
const int MAXN=10000;
long long island[MAXN];
int adj[MAXN][MAXN];
int sl[MAXN][MAXN];
int ans;


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	scanf("%d%d",&c,&t);
	for(int test_=1;test_<=t;test_++)
	{
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&island[i]);
			for(int j=1;j<=n;j++)
			{
				adj[i][j]=0;
				sl[i][j]=0;
			}
			adj[i][i]=MAXN+1;
		}
		for(int i=1;i<n;i++)
		{
		    for(int j=i+1;j<=n;j++)
		    {
		    	if((island[j]-island[i])<=d && (island[i]-island[j])<=d)
		    	{
		    		adj[i][j]=1;
		    		adj[j][i]=1;
		    		sl[i][j]=1;
		    		sl[j][i]=1;
				}else
				{
					adj[i][j]=MAXN+1;
					adj[j][i]=MAXN+1;
				}
				
			}
		}
		
		for(int m=1;m<=n;m++)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(adj[i][j]==(adj[i][m]+adj[m][j]))
					{
						
						sl[i][j]++;
					}else if(adj[i][j]>(adj[i][m]+adj[m][j]))
					{
						adj[i][j]=adj[i][m]+adj[m][j];
						sl[i][j]+=sl[i][m]*sl[m][j];
					}
				}
				
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(sl[i][j]==2)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
