#include<bits/stdc++.h>
#define int long long 
#define sc(x) scanf("%lld",&x) 
using namespace std;
int c,t,n,d,a[2000005],l1,l2,m1,m2,r2,r1,da; 
bool q;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	sc(c);sc(t);
	while(t--)
	{
		sc(n);sc(d);
		for(int i=1;i<=n;i++)
		{
			sc(a[i]);
		}
		da=0;
		l1=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[1]>d)
			{
				m2=i-1;
				break;
			}
		}
		m1=m2-1;
		for(int i=l2;i<=n;i++)
			{
				if(a[m2+1]-a[i]<=d)
				{
					l2=i-1;
					break;
				}
			}
			for(int i=r2;i<=n;i++)
			{
				if(a[i]-a[m1]>d)
				{
					r2=i-1;
					break;
				}
			}
			for(int i=r1;i<=n;i++)
			{
				if(a[i]-a[m1-1]>d)
				{
					r1=i;
					break;
				}
			}
		for(int j=m1;j<=n-1;j++)
		{
			m1=j,m2=j+1;
			q=false;
			for(int i=l1;i<=n;i++)
			{
				if(a[m2]-a[i]<=d)
				{
					l1=i;
					break;
				}
			}
			for(int i=l2;i<=n;i++)
			{
				if(a[m2+1]-a[i]<=d)
				{
					l2=i-1;
					break;
				}
			}
			for(int i=r2;i<=n;i++)
			{
				if(a[i]-a[m1]>d)
				{
					r2=i-1;
					break;
				}
			}
			for(int i=r1;i<=n;i++)
			{
				if(a[i]-a[m1-1]>d)
				{
					r1=i;
					break;
				}
			}
			if(!q) 
			if((l2-l1+1)*(r2-r1+1)>=0)
			da+=(l2-l1+1)*(r2-r1+1);
		}
		printf("%lld\n",da);
	}
	return 0;
}
