#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],s=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n-1;++i)
	{
		m=m-a[i+1]+a[i]-i*(a[i+1]-a[i]);
		if(m<0)
		{
			break;
		}
		++s;
	}
	printf("%lld",s);
	return 0;
} 
