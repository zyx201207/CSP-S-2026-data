#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long s[1000005];
long long f[1000005];
bool check(long long x)
{
	int minn=2e18;
	for(long long i=1,a=0;i+x-1<=n;i++)
	{
		a=f[i+x-1]-f[i]-(i-1)*(s[i+x-1]-s[i]);
		//cout<<x<<" "<<i<<" "<<a<<"\n";
		minn=minn<a?minn:a;
	}
	return minn<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf(" %lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf(" %lld",&s[i]);
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+(i-1)*(s[i]-s[i-1]);
	long long l=1,r=n,mid=0;
	while(l<r)
	{
		mid=r-((r-l)>>1);
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
 } 
