#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,a[N],ans=0;
ll sum[N/2+1];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		cin>>c[i];
	}
	ll ui=1,uj=n,cnt1=0,cnt2=0;
	for(int i=1;i<=sum[n/2];i++)
	{
		if(cnt1==a[ui])
		{
			ui++;
			cnt1=0;
		}
		if(cnt2==a[uj])
		{
			uj--;
			cnt2=0;
		}
		if(c[ui]!=c[uj])
		{
			ans++;
		}
		cnt1++;
		cnt2++;
	}
	printf("%lld",ans);
	return 0;
}
