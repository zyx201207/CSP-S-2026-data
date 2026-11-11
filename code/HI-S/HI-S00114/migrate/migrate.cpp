#include<bits/stdc++.h>
using namespace std;
long long c,dis,m,t,n,d,ans=0;
int x[100000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long ls,dif;
	cin>>c>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(long long j=0;j<n;j++)
		{
			cin>>ls;
			if(j==0)
			{
				dif=ls;
			}
			if(j==1)
			{
				dif=ls-dif;
			}
		}
		for(long long m=1;m<n;m++)
		{
			for(long long k=0;k<m;k++)
			{
				if((m-k)*dif>d)
				{
					
					dis=(dif*(m-k))/d+1;
					if(dis==2)
					{
						ans+=1;
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
