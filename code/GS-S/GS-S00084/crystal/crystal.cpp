#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],l=99999999999999,r=-9999999999999,ans=0,l1,r1;
long long lr(long long y)
{
	long long i,mi;
	l1=1;
	r1=n;
	while(l1<=r1)
	{
		mi=(l1+r1)/2;
		if(y<a[mi])
		{
			r1=mi-1;
		}
		else
		{
			l1=mi+1;
		}
	}
	return mi;
}
bool dx(long long x)
{
	long long m1=0,ans1=0;	
	for(long long i=lr(x);i>=1;i--)
	{
		if(x==a[i])
		ans1++;
		else
		{
			if(m1<m)
			{
				m1+=x-a[i];
				ans1++;
			}			
		}
	}
	if(m1>m)
	ans1--;
	ans=max(ans,ans1);
	if(m!=0)		
	if(m1<=m)
	{
		return true;
	} 
	else
	return false;
	
	
}
void zcx(long long l,long long r)
{	
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(dx(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(l>a[i])
		l=a[i];
		if(a[i]>r)
		r=a[i];
	}
	sort(a+1,a+n+1);
	zcx(l,r);
	cout<<ans-1;
	return 0;
 } 
