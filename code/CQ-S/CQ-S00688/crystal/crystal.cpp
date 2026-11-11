#include <bits/stdc++.h>
using namespace std;

const int N=5*1e5+10;
long long n,m;
long long a[N],c[N],tag[N];

long long len(long long l,long long r)
{
	return c[r]-c[l]-(l-1)*tag[l+1];
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if((a[i]-a[i-1])!=0)
		{
			tag[i]=a[i]-a[i-1];
		}
		c[i]=c[i-1]+(i-1)*tag[i];
	}
	long long maxn=1;
	long long l=1,r=1;
	while(r<=n)
	{
		int t=len(l,r);
		while(t<=m && r<=n && t>=0)
		{
			if((r-l+1)>maxn)
			{
				maxn=r-l+1;
				//printf("%d %d %d\n",r,l,len(l,r));
			}
			if(r<=n)
			{
				r++;
			}
			t=len(l,r);
			printf("%d %d %d %d\n",r,l,len(l,r),r-l+1);
		}
		l++;
	}
	printf("%lld",maxn);
	return 0;
}
