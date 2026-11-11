#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n,m;
ll a[N],d[N],b[N],c[N];
bool check(ll);
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
		d[i] = a[i] - a[i - 1];
	for(int i = n;i >= 1;i--)
		b[i] = d[i] * (i - 1);
	for(int i = 1;i <= n;i++)
		c[i] = c[i - 1] + b[i];//right
	int l = 0,r = n + 1,mid;
	while(r > l + 1)
	{
		mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}
bool check(ll x)
{
	for(int l = 1;l <= n - x + 1;l++)
	{
		ll r = l + x - 1;
		ll ans = c[r];
		ll t = c[l];
		t = t + (a[r] - a[l]) * (l - 1);
		ans -= t;
		if(ans <= m) return true;
	}
	return false;
}
