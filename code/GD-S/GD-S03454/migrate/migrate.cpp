#include<bits/stdc++.h>
using namespace std;
int g[2010][2010],s[2010][2010],a[2010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		memset(g,0x3f,sizeof(g));
		int n,d,l=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					g[i][j]=0x3f3f3f3f;
				else
				{
					if(abs(a[i]-a[j])>d)
						g[i][j]==0x3f3f3f3f;
					else
						g[i][j]=1;
				}
					
			}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(i!=j&&i!=k&&j!=k)
					{
						if(g[i][k]+g[k][j]==g[i][j])
						{
							s[i][j]++; 
						}
						if(g[i][k]+g[k][j]<g[i][j])
						{
							s[i][j]=1;
							g[i][j]=g[i][k]+g[k][j];
						}
					}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(s[i][j]==2)
					l++;
			}
		cout<<l<<endl;
	}
	return 0;
}
