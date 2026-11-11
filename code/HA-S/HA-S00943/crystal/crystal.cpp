#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, sum = 0, maxn;
ll a[500010], c[500010], s[500010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		c[i] = a[i] - a[i-1];
		sum += c[i] * (i - 1);
	}
	c[1] = 0;
	for(int i = 1; i <= n; i++)
	{
		s[i] = c[i] + s[i-1];
	}
	ll l = 1, r = 1, su = 0;
	while(l <= r && r <= n)
	{
		su += c[++r] * (r - l);
		if(su > m)
		{
			while(l < r && su > m)
			{
				su -= (s[r] - s[l]);
				l++;
			}
		}
		maxn = max(maxn, (r - l + 1));
	}
	cout << maxn << "\n";
	return 0;
}
