#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long s[100005];
long long n,m;
long long maxn=-1e13;
bool check(long long x)
{
	long long t=1e18;
	for(int i=1;i<=n-x+1;i++)
	{
		long long j=i+x-1;
		long long k=maxn-a[j];
		t=min(t,(s[j]-s[i-1])-k*x);
	}
	return t<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(maxn-a[i]);
	}
	long long l=0;
	long long r=n;
	long long ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
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
