#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N];
int maxx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(register int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(register int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(register int i=1;i<=n;++i)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			long long len=i-mid+1;
			if(len*a[i]-(s[i]-s[i-len])>m) l=mid+1;
			else r=mid-1;
		}
		maxx=max(maxx,i-l+1);
	}
	printf("%lld",maxx);
	return 0;
 } 
