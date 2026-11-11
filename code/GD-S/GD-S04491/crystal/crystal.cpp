#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

ll n,m;
ll a[N],sum[N];
ll ww,ans;

void gc()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++)sum[i]=sum[i-1]+a[i];
	ww=1;
	for (int i = 1;i <= n;i++)
	{
		while ((i-ww+1)*a[i]-(sum[i]-sum[ww-1])>m)ww++;
		ans=max(ans,i-ww+1);
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	gc();
	return 0;
}
