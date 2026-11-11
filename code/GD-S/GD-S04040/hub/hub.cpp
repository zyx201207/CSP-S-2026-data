#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[500005];
bool check(long long x)
{
	long long sum=0;
	for(int i=1;i<x;i++)
	{
		sum+=s[x]-s[i];
		if(sum>m)
			return 0;
	}
	return 1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf(" %lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf(" %lld",&s[i]);
	sort(s+1,s+1+n);
	long long l=1,r=n,mid=0;
	while(l<r)
	{
		mid=r-((r-l)>>1);
		if(check(mid)) l=mid;
		else r=mid-1;	
	}
	printf("%lld",&l);
	return 0;
 } 
