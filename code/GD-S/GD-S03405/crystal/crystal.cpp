#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000009],t[1000009],i1,sum,ans;
void sort_(long long l,long long r)
{
	if(l>=r)return;
	long long mid=(l+r)/2;
	sort_(l,mid);
	sort_(mid+1,r);
	long long i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
		{
			++k;
			t[k]=a[i];
			++i;
		}
		else
		{
			++k;
			t[k]=a[j];
			++j;
		}
	}
	while(i<=mid)
	{
		++k;
		t[k]=a[i];
		++i;
	}
	while(j<=r)
	{
		++k;
		t[k]=a[j];
		++j;
	}
	for(i=0;i<k;++i)
	{
		a[i+l]=t[i+1];
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort_(1,n);
	i1=1;
	sum=0;
	ans=1;
	for(int i=2;i<=n;++i)
	{
		sum+=(a[i]-a[i-1])*(i-i1);
		while(sum>m)
		{
			sum-=a[i]-a[i1];
			++i1;
		}
		if(i-i1+1>ans)ans=i-i1+1;
	}
	printf("%lld",ans);
	return 0;
}
