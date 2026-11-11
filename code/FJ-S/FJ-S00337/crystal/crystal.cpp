#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int k=1,t=1,u=1;
	for(int i=2;i<=n;i++)
	{
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])u=0;
		if(a[i]!=a[i-1]) 
		{
			k=max(k,t);
			t=1;
		}
		else t++;
	}
	k=max(k,t);
	if(u)
	{
		int e=a[2]-a[1],w=1;
		int r=e;
		if(e>m)
		{
			printf("1");
			return 0;
		}
	    while(r+(w+1)*e<=m&&w+1<n)
	    {
	    	w++;
	    	r+=w*e;
		}
		printf("%lld",w+1);
		return 0;
	}
	int mi=a[k],ma=a[n];
	for(int j=mi;j<=ma;j++)
	{
		int l=0,r=n+1;
		while(l!=r-1)
		{
			int mid=l+r>>1;
			if(a[mid]<=j)l=mid;
			else r=mid;
		}
		int u=0,p=0;
		for(int i=l;i>=1;i--)
		{
			if(u+j-a[i]<=m)
			{
				u=u+j-a[i];
				p++;
			}
			else break;
		}
		k=max(k,p);
	}
	printf("%lld",k);
	return 0;
}
