#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2e6 + 5; 
ll c, t;
ll n, d;
ll a[MAXN];
ll r[MAXN], l[MAXN];
ll find(ll start, ll x, ll y, ll s)
{
	if(abs(a[x + y] - a[start]) <=d)
	{
		s++;
		s = find(start, x + y, y, s);
	}
	return s;
}
ll dfsm(ll start, ll end, ll minn, ll length)
{
	if(start == end)
	{
		return min(minn, length);
	}
	for(ll i = 1; i <= r[start]; i++)
	{
		minn = dfsm(start + i, end, minn, length + 1);
	}
	return minn;
}
ll dfss(ll start, ll end, ll minn, ll ans, ll length)
{
	if(start == end)
	{
		if(minn == length) return ans + 1;
		else return ans;
	}
	for(ll i = 1; i <= r[start]; i++)
	{
		ans = dfss(start + i, end, minn, ans, length + 1);
	}
	return ans;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	scanf("%lld %lld", &c, &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &d);
		for(ll i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		a[0] = a[n + 1] = 11451411;
		for(ll i = 1; i <= n; i++)
		{
			l[i] = find(i, i, -1, 0);
			r[i] = find(i, i, 1, 0);
		}
		ll ans = 0; 
		for(ll i = 1; i <= n - 3; i++)
		{
			for(ll j = i + 3; j <= n; j++)
			{	
				if(dfss(i, j, dfsm(i, j, 11451411, 0), 0, 0) == 2) ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
