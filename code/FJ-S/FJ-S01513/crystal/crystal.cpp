#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct aaa
{
	long long x,y,z;
}a[1000005];
bool cmp(aaa x,aaa y)
{
	return x.x<y.x;
}
bool check(long long x)
{
	long long q=m;
	for(int i=n;i>x;i--)
	{
		if(a[i].z-a[i-x].z-a[i].y*(x-1)<=q)
			return 1;	
	}
	if(a[x].z-x*a[x].y<=q)
		return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		a[i].y=a[n].x-a[i].x;
		a[i].z=a[i-1].z+a[i].y;
	}
	long long l=1,r=n,mid=(l+r)/2,ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

