#include<bits/stdc++.h> 
using namespace std;
int x[10000],sum;
int dp[100000][10000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) 
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			sum=sum[i-1]+x[i];
		}
		dp[u][v]=1;
		for(int u=1;u<=n;u++)
		{
			for(int v=u;v<=n;v++)
			{
				if(x[v]-x[u]<d)
				{
					dp[v][u]
				}
			}
		}
	}
	return 0;
}

