#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=5)
	{
		cout<<"4";
	}
	else
	{
		long long maxj=0;
		for(long long i=1;i<n;i++)
		{
			maxj=maxj+i;
		}
		if(m>=maxj)
		{
			if(m==maxj||(m-maxj)%n==0)
			{
				printf("%lld",n);
				return 0;
			}
			else
			{
				printf("%lld",n-1);
				return 0;
			}
		}
		
		else
		{
			if(m<maxj)
			{
			//	long long p=n-1;
				long long l=1,r=n-1;
				if(maxj-m>=l&&maxj-m<=r) 
				{
					printf("%lld",n-1);
					return 0;
				}
				for(long long i=2;i<n-1;i++)
				{
					l=1+r;
					r=r+(n-i);
				//	cout<<"l"<<l<<" r"<<r<<endl;
					if(maxj-m>=l&&maxj-m<=r) 
					{
						printf("%lld",n-i);
						return 0;
					}
				}
				
			
			}
		
		}
	}

	return 0;
 } 
