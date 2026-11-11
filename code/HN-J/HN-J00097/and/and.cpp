#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 2e5 + 5;

struct node
{
	ll data, count;
}a[NR];

ll count_1(ll x)
{
	ll cnt = 0;
	while(x)
	{
		if(x % 2 == 1) cnt++;
		x /= 2;
	}
	return cnt;
}

bool cmp(node x, node y)
{
	if(x.count != y.count) return x.count > y.count;
	return x.data > y.data;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		ll x;
		cin >> x;
		a[i] = {x, count_1(x)};
	}
	sort(a+1, a+n+1, cmp);
	ll ans = a[1].data;
	for(int i = 2; i <= m; i++)
		ans &= a[i].data;
	cout << ans;
	return 0;
}
