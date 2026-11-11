#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200005
#define fr(i, l, r) for(ll i = l; i <= r; i++)
struct node
{
	ll x;
	char y;
}a[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	cin >> n;
	fr(i, 1, n)
	{
		cin >> a[i].x >> a[i].y;
	}
	ll ans = 0, t;
	for(ll l = 1, r = n; l < r;)
	{
		t = min(a[l].x, a[r].x);
		if(a[l].y != a[r].y)
		{
			ans += t;
		}
		a[l].x -= t;
		a[r].x -= t;
		if(!a[l].x)l++;
		if(!a[r].x)r--;
	}
	cout << ans;
	return 0;
}
//fc string.out string.ans
