#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,l=0,r=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0) r=a[i];
		r=max(r,a[i]);
		l=min(l,a[i]);
	}
	sort(a,a+n);
	r+=m;
	long long maxb=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		for(int i=0;i<n;i++)
		{
			b[i]=mid-a[i];
		}
        sort(b,b+n);
		int x=0;
		for(int i=0;i<n;i++)
		{
			if(b[i]>=0)
			{
				x=i;
				break;
			}
		}
		long long c=0,t=0;
		for(int i=x;i<n;i++)
		{
			if((c+b[i])>m)
			{
				break;
			}
			c+=b[i];
			t++;
		}
		maxb=max(maxb,t);
		if((n-x)==t) l=mid+1;
		else r=mid-1;
	}
	cout<<maxb;
	return 0;
}
