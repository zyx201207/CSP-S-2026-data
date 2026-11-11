#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5e5 + 5; 
ll n, m;
ll a[MAXN], b[MAXN];
bool cmp (ll x, ll y)
{
	return x < y;
}
int main()
{
	ll maxn = 0;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	for(ll i = 2; i <= n; i++) b[i] = a[i] - a[i - 1];
	for(ll i = 1; i < n; i++)
	{
		ll s, cnt;
		s = cnt = 0;
		for(ll j = i + 1; j <= n && s <= m; j++)
		{
			cnt++;
			s += b[j] * cnt;
		}
		maxn = max(maxn, cnt);
	}
	cout << maxn;
	return 0;
}
