#include<bits/stdc++.h>
using namespace std; 
long long c,n,m,d,q,ma[505],a[5*100000+5],maxx;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&ma[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		long long sun=0;
		for(int j=1;j<=a[i];j++)
		{
			long long ans,t;
			cin>>ans>>t;
			sun+=ans;
		}
		maxx=max(maxx,sun);
	}
	printf("%lld%lld",maxx,maxx/2);
	return 0;
}
