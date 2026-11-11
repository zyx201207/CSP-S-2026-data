#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000001],sum,ans;
bool fd(long long x,long long i)
{
	long long l=1,r=n,awa;
	while(l<r)
	{
		awa=(l+r)/2;
		if(a[awa]>x) r=awa;
		else l=awa+1;
	}
	if(a[awa]==x&&abs(awa-i)!=1) return true;
	return false;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		for(int i=1;i<=sum;i++) a[i]=0;
		cin>>n>>d;sum=n;
		for(int i=1;i<=n;i++) {cin>>a[i];if(fd(a[i]-d*2+1,i)) ans++;}
		cout<<ans<<"\n";
	}
}
