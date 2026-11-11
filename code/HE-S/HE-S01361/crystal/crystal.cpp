#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans,maxn=-5545587;
map<long long,long long> k;
bool check(long long x)
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(x>=a[i])
			sum+=x-a[i];
		else
			break;
	}
	return sum>=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k[a[i]]++;
	}
	sort(a+1,a+1+n);
	long long l=-10000000,r=100000000000;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=l)
		{
			ans=i;
		}	
		maxn=max(maxn,k[a[i]]);	
	}	
	printf("%lld",max(maxn,ans));
}
