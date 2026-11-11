#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long p=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++)
		{
			long long l=0;
			for(long long z=n;z>i;z--)
			{
				for(long long j=i+1;j<z;j++)
				{
					if(abs(a[j]-a[i])<d && abs(a[z]-a[j])<=d)
					{
						l++;
					}
				}
			}
			if(l==2)
			{
				p++;
			}
		}
		cout<<p<<endl;
	}
	return 0;
}
