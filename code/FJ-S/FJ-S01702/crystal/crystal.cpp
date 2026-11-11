#include<bits/stdc++.h>
using namespace std;
long long a[500100];
long long pp(long long t,long long w)
{
	return (a[w]-a[w-1])*(w-t+1)-a[w]+a[t-1];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		a[i]+=a[i-1];
	long long t=1,w=1;
	while(w<=n)
	{
		while(pp(t,w)<=m&&w<=n)
		{
			ans=max(ans,w-t+1);
			w++;
		}
		t++;
	}
	printf("%lld",ans);
	return 0;
} 
