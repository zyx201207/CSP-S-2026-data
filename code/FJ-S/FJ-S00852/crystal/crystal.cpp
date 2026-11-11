#include<bits/stdc++.h>
using namespace std;
#define N 500005
typedef long long ll;
#define fr(a, b, c) for(ll a = b; a <= c; a++)
#define relx(a, b) (a) = max(a, b)
ll a[N];
ll h[N], td[N];
ll n, m;
#define calc(x, mid) (td[x] - mid * a[x] + h[mid])
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	fr(i, 1, n)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	fr(i, 1, n)
	{
		h[i] = h[i - 1] + a[i];
		td[i] = (i - 1) * (a[i] - a[i - 1]) + td[i - 1];
	}
	ll ans = 0;
	fr(i, 1, n)
	{
		ll l = 0, r = i - 1, tot, mid;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(calc(i, mid) <= m)
			{
				tot = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		relx(ans, i - tot);
	}
	cout << ans;
	return 0;
}
//fc crystal.out crystal.ans
