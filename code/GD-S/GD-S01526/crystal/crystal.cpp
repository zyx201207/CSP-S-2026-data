#include <iostream>
using namespace std;
const long long N=5e5+5;
long long n,m;
long long a[N],s[N],ans;
void qs(long long s,long long e)
{
	if(s>=e) return ;
	long long mid=a[(s+e)>>1];
	long long l=s,r=e;
	while(l<=r)
	{
		while(a[l]<mid) l++;
		while(mid<a[r]) r--;
		if(l<=r)
		{
			swap(a[l],a[r]);
			l++,r--;
		}
	}
	qs(s,r);
	qs(l,e);
}

void bs(long long x)
{
	long long l=1,r=x-1;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		if(a[x]*(x-mid)-(s[x-1]-s[mid-1])>m)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if(a[x]*(x-r)-(s[x-1]-s[r-1])<=m)
	{
		ans=max(ans,x-r+1);
	} 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	qs(1,n);
	long long p=2,sum=0,ans=0;
	for(long long i=1;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-p+1);
		while(sum>m)
		{
			sum-=(a[i]-a[p-1]);
			p++;
		}
		ans=max(ans,i-p+2);
	}
	cout<<ans;
	return 0;
}
