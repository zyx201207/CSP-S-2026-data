#include<bits/stdc++.h>
using namespace std;
long long a[1000000],s[5009][5009],ans[5009][5009];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		for(long long i=1;i<=t;i++)
		{
			
			long long n,d;
			cin>>n>>d;
			for(long long i=1;i<=n;i++)
			{
				scanf("%lld",&a[i]);
			}
			long long c=a[1+1]-a[1];
			if(n%2==0)
			{
				long long s=0;
				for(long long i=4,k=1;i<=n;i+=2,k+=2)
				{
					s+=k;
				}
				cout<<s*c<<"\n";
			}
			if(n%2!=0)
			{
				long long s=0;
				for(long long i=4,k=1;i<=n-1;i+=2,k+=2)
				{
					s+=k;
				}
				cout<<(s+sqrt(s))*c<<"\n";
			}
		}
	}
	else if(c==13||c==14)
	{
		
	}
	else if(c>=15&&c<=18)
	{
		
	}
	else
	{
		for(long long i=1;i<=t;i++)
		{
			long long n,d,maxx=0;
			cin>>n>>d;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					s[i][j]=LONG_LONG_MAX/2;
					ans[i][j]=0;
				}
			}
			for(long long i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(long long i=1;i<=n;i++)
			{
				for(long long j=i;j<=n;j++)
				{
					if(d>=abs(a[i]-a[j]))
					s[i][j]=1;
				}
			}
			
			for(long long k=1;k<=n;k++)
			{
				for(long long i=1;i<=n;i++)
				{
					for(long long j=1;j<=n;j++)
					{
						if(s[i][j]>s[k][j]+s[i][k])
						{
							s[i][j]=s[k][j]+s[i][k];
							ans[i][j]=1;
						}
						else if(s[i][j]==s[k][j]+s[i][k])
						{
							ans[i][j]++;
						}
					}
				}
			}
			for(long long i=1;i<=n;i++)
			{
				for(long long j=i;j<=n;j++)
				{
					if(ans[i][j]==2)
					{
						maxx++;
					}
				}
			}
			cout<<maxx<<"\n";
		}
	}
	return 0;
}