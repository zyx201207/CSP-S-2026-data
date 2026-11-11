#include <bits/stdc++.h>
#define N 500010
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n;
ll m,ans,num,l = inf,r = -inf,a[N];
bool check(ll x)
{
	ll sum = 0;
	for (int i = 1;i <= n;++i)
		if (a[i] <= x) sum += (x - a[i]);
	return sum <= m;
}
int main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i];
		l = min(a[i],l);
		r = max(a[i],r);
	} 
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		if (check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	for (int i = 1;i <= n;++i)
		if (a[i] <= ans) ++num;
	cout << num;
	return 0;
}
/*
5 7
2 3 1 5 6 10
*/
