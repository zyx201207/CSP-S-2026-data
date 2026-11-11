#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10; 

typedef long long ll;
ll a1[N] , a2[N] , a3[N];
ll minn = -1;

int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ll n , m;
	scanf("%lld%lld" , &n , &m);
	
	for(ll i = 1 ; i <= n ; ++ i)
	{
		scanf("%lld" , &a1[i]);
		if(i >= 2)
		{
			a2[i - 1] = abs(a1[i] - a1[i - 1]);
		}
	}
	for(ll i = n ; i >= 1 ; i --)
	{
		a3[i] = a3[i + 1] + a2[i];
	}
	
	for(ll i = 1 ; i <= n ; ++ i)
	{
		ll temp = 0;
		for(ll j = 1 ; j <= i ; ++ j)
		{
			temp += a3[j] - a3[i];
		}
		if(temp <= m && i >= minn)
		{
			minn = i;
		}
	}
	
	printf("%lld" , minn);
	
	return 0;
}
