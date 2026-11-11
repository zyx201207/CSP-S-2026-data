#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 5e5 + 5;

ll arr[N],n,m;
int main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i++)
		scanf("%lld",arr + i);
	sort(arr + 1,arr + n + 1);
	ll p = 1;
	ll s = 0;
	ll ans = 0;
	for(ll i = 1;i <= n;i++)
	{
		s += (arr[i] - arr[i - 1]) * (i - p);
		while(s > m)
		{
			s -= (arr[i] - arr[p]);
			p++; 
		}
		ans = max(ans,i - p + 1);
	}
	printf("%lld\n",ans);
	return 0;
}
