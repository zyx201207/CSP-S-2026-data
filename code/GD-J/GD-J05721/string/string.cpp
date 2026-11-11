#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll a[N];
char c[N];
ll n;
ll s;
void solve()
{
	ll i=1,j=n;
	ll sumi=a[1],sumj=a[n];
	ll lst=0;
	while(i<j)
	{
		if(sumi==sumj)
		{
			s+=(sumi-lst)*(c[i]!=c[j]);
			lst=sumi;
			sumi+=a[++i],sumj+=a[--j];
		}
		if(sumi>sumj)
		{
			s+=(sumj-lst)*(c[i]!=c[j]);
			lst=sumj;
			sumj+=a[--j];
		}
		if(sumi<sumj)
		{
			s+=(sumi-lst)*(c[i]!=c[j]);
			lst=sumi;
			sumi+=a[++i];
		}
	}
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld %c",&a[i],&c[i]);
	solve();
	printf("%lld",s);
	return 0;
}
