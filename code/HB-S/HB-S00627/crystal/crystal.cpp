/*
I have a ton of homework to do.
It's the last OI contest of my junior high school period.
*/

#include <bits/stdc++.h>
using namespace std;

const long long MAXN=5e5+10;
long long a[MAXN];
long long n,m,k,ans;

long long solve(long long x)
{
	k=a[x];
	long long sum=0,cnt=1;
	for(long long j=x-1;j>=1;j--)
	{
		if(sum+k-a[j]<=m)
		{
			sum+=k-a[j];
			cnt++;
		}
		else
			break;
	}
	return cnt;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	
	for(long long i=1;i<=n;i++)
		ans=max(ans,solve(i));
	printf("%lld\n",ans);
	return 0;
}