#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],js=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&c[i]);
	for(int i=1,j=n;i<j;)
	{
		if(a[i]>a[j])
		{
			if(c[j]!=c[i])
				js+=a[j];
			a[i]-=a[j];
			j--;
		}
		else
		{
			if(c[j]!=c[i])
				js+=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	printf("%lld",js);
	return 0;
}
