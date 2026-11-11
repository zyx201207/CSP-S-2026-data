#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int f[5005][5005];
int a[5005][5005];
int dis[5005][5005];
int x[5005];
int la[5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n,d,ans=0;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=a[i][j]=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(x[j]-x[i]>d)
			{
				break;
			}
			la[i]=j;
		}
		for(int i=1;i<=n;i++)
		{
			int x=i,y=la[x];
			int p=1;
			while(1)
			{
				for(int j=x+1;j<=y;j++)
					a[i][j]=p;
				p++;
				x=y;
				if(y==la[y])
					break;
				y=la[y];
			}
		}
		for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if(a[i][j]==1||a[i][j]==0)
			{
				dis[i][j]=1;
				continue;
			}
			for(int k=i+1;k<j;k++)
			{
				if(a[i][k]>=2)
					break;
				if(a[k][j]+1==a[i][j])
				{
					dis[i][j]+=dis[k][j];
					if(dis[i][j]>=3)
					{
						dis[i][j]=3;
						break;
					}
				}
			}
			if(dis[i][j]==2)
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
