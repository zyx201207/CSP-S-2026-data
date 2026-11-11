#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool cmp(long long x,long long y)
{
	return x>y;
}
bool check(int x)
{
	long long cnt=0,h=1;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i];
		if(i-h+1>=x)
		{
			if(a[h]*x-cnt<=m)
			{
				return 1;
			}
			cnt-=a[h];
			h++;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	long long L=1,R=n,mid;
	while(L<R)
	{
		mid=(L+R+1)/2;
		if(check(mid))
		{
			L=mid;
		}
		else
		{
			R=mid-1;
		}
	}
	cout<<L;
	return 0;
}
