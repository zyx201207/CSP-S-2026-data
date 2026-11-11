#include<iostream>
#include<cstdio>

using namespace std;

const int N=2e6+5;

int c,t,n,d,ans,x[N],l[5005][5005];
bool f;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		f=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			l[i-1][i]=x[i]-x[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					l[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=i+1;k<j;k++)
				{
					if(l[i][j]==l[i][k]+l[k+1][j])
					{
						if(f)  ans++;
						f=0;
					}
					l[i][j]=min(l[i][j],l[i][k]+l[k+1][j]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
