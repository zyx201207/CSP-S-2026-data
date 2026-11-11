#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		long long m=1,k1=1,k2=1,s=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i-m>=3)
			{
				if((a[i]-a[i-3]>d)and(a[i]-a[i-1]<=d)and(a[i]-a[i-2]<=d)and(a[i-1]-a[i-3]<=d)and(a[i-2]-a[i-3]<=d))
				{
					if(k1!=k2)
					{
						if(m==k2)
						{
							s=s+(i-k1)*(k1-k2-2);
						}
						else
						{ 
							s=s+(i-k1)*(k1-k2);
						}
					}
					k2=k1;
					k1=i;
					//cout<<s<<" ";
				}
				if(i==n and k1!=m) 
				{
					if(k2==m)
					{
						s=s+i-k1+1;
					}
					else
					{
						s=s+(k1-k2)*(i-k1+1);
					}
				}
				if(a[i]-a[i-1]>d)
				{
					if(k2==m)
					{
						s=s+i-k1;
					}
					else
					{
						s=s+(k1-k2)*(i-k1);
					}
					m=k1=k2=i;
				}
			}
		}
		printf("%lld\n",s);
	}
}
