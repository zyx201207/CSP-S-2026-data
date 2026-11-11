#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),cin>>c[i];
	for(int i=1,j=n;i<j;)
	{
		if(a[i]==a[j])
		{
			if(c[i]!=c[j]) ans+=a[i];
			i++,j--;
		}
		else if(a[i]<a[j])
		{
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else
		{
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	printf("%lld",ans);
	return 0;
}
