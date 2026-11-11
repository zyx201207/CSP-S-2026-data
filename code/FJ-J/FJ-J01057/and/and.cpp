#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200005
#define fr(i, l, r) for(ll i = l; i <= r; i++)
#define mem(a, b) memset(a, b, sizeof(a))
ll a[N];
bool f1[N], f2[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	fr(i, 1, n)
	{
		cin >> a[i];
	}
	mem(f1, 1);
	ll tot, t, ans;
	for(ll k = 30; k >= 0; k--)
	{
		tot = 0;
		fr(i, 1, n)
		{
			t = (a[i] >> k) & 1;
			f2[i] = f1[i] && t;
			if(f2[i])tot++;
		}
		if(tot < m)continue;
		fr(i, 1, n)f1[i] = f2[i];
	}
	tot = 0;
	ans = (1ll << 31) - 1;
	fr(i, 1, n)
	{
		if(f1[i])
		{
			ans &= a[i];
			tot++;
		}
		if(tot == m)break;
	}
	cout << ans;
	return 0;
}
//fc and.out and.ans
