#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
ll a[N];
ll n,m,ans,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i ++)scanf("%lld",a + i);
	sort(a + 1,a + n + 1);
	ll l = 1;
	for(int r = 1;r < n;r ++)
	{
		sum += a[r];
		while(l < r && a[r]*(r-l+1) - sum > m)sum -= a[l],l ++;
		ans = max(ans,r - l + 1);
	}
	printf("%lld",ans);
	return 0;
} 
