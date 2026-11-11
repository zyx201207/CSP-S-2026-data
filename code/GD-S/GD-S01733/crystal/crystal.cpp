#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

ll n , m , a[N] , l = INF , r = -INF , ans = -INF , c[N];



int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	cin >> n >> m;
	ll tmp = 1;
	for(ll i = 1; i<=n; i++)
	{
		cin >> a[i];
		r = max(a[i] , r);
		l = min(a[i] , l);
	}
	for(ll mid = l; mid<=r; mid++)
	{
		for(ll i = 1; i<=n; i++)
		{
			c[i] = abs(a[i] - mid);
			c[i] += c[i - 1];
		}
		ll cnt;
		for(ll i = 1; i<=n; i++)
		{
			cnt = 0;
			for(ll j = 1; j<=n; j++)
			{
				if(m - c[j] >= 0)
					cnt = j;
				else
					break;
			}
			ans = max(ans , cnt);
		}
	} 
	cout << ans;
	
	return 0;
}
