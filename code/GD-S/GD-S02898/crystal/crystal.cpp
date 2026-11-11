#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1e18,a[500020],cnt;
long long chk(long long x)
{
	long long sum=0,cnt=0;
	int p=upper_bound(a+1,a+n+1,x)-a-1;	
	for(int i=p;i>=1;i--)
	{
		sum+=max(x-a[i],0LL);
		if(sum>m) break;
		cnt++;
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int s=0,len=n/2;
	for(int i=1;i<=1000;i++)
	{
		s+=len;
		if(s>n) s-=len,len=len/2,s-=len;
		long long ck=chk(a[s]);
		ans=max(ans,ck);
		if(ck>chk(a[min(n,(long long)s+len)])) len=-len/2;
		if(len==0) len=n/2;
	}
	printf("%lld",ans);
	return 0;
}
