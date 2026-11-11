#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
dis[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		reserve(a+1,a+n+1);
		for (int i=1;i<=n;i++)
		{
			dis[i][i+1]=1;
		}
		for (int k=1;k<=n;k++)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		cout<<dis[1][n];
	}	
	return 0;
}
