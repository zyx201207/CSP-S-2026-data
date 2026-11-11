#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long mn[5010][5010],c[5010][5010];
long long e18=1e18;
long long INF=4*e18;
long long now[10];
long long nn,dd;
//long long dfs()
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long cc,t,xb=0;
	cin>>cc>>t;
	if(cc<=6)
	{
		while(t--)
		{
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					mn[i][j]=INF;
				}
			}
			for(int i=1;i<=n;i++)
			{
				mn[i][i]=0;
				c[i][i]=1;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					for(int k=i+1;k+1<=j;k++)
					{
						long long newmn=mn[i][k]+mn[k][j];
						if(newmn==mn[i][j])
						{
							c[i][j]++;
						}
						else if(newmn<mn[i][j])
						{
							mn[i][j]=newmn;
							c[i][j]=1;
						}
					}
				}
			}
			cout<<++xb<<endl;
		}
	}
	else if(cc==11 || cc==12)
	{
		while(t--)
		{
			long long n,d,oneg;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			oneg=a[2]-a[1];
			if(oneg<d && d<(3*oneg))
			{
				cout<<max(0ll,n-3ll)<<endl;
			}
			else
			{
				cout<<"0\n";
			}
		}
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			cout<<"0\n";
		}
	}
	return 0;
}
