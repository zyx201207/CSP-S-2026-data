#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
bool check(int x)
{
	for(int i = 1;i <= n-x;i++)
	{
		long long cnt = b[i+x-2];
		for(int j = i;j < i+x-2;j++)
		{
			cnt+=b[i+x-2]-b[j];
		}
		if(cnt<=m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i < n;i++)
	{
		b[i] = a[i+1]-a[1];
	}
	long long l = 1,r = m,mid;
	while(l < r)
	{
		mid = (l+r)>>1;
		if(check(mid))
		{
			l = mid+1;
			ans = max(ans,mid);
		}
		else
		{
			r = mid;
		}
	}
	printf("%lld",ans);
	return 0;
}
//RP++
