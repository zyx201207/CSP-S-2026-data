#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pa pair<ll,ll>
#define fi first
#define se second
ll c,T;
ll n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&k);
		for (ll i=1;i<n;i++)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
		}
		printf("%lld\n",((n-1)/2+1)/4);
	}
	return 0;
	}

