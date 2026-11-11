#include<bits/stdc++.h>
using namespace std;
long long n,a[541145],c[541145],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld %c ",&a[i],&c[i]);
	for(int i=1,j=n;i<j;)
	{
		if(a[i]<a[j]) s+=(c[i]!=c[j])*a[i],a[j]-=a[i],i++;
		else if(a[i]>a[j]) s+=(c[i]!=c[j])*a[j],a[i]-=a[j],j--;
		else s+=(c[i]!=c[j])*a[i],i++,j--;
	}
	printf("%lld",s);
	return 0;
}
