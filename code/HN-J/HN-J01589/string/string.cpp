#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
ll ans = 0;

int main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	s = " ";
	for (ll i = 1; i <= n; i++)
	{
		ll a;
		char c;
		cin >> a >> c;
		for (ll j = 1; j <= a; j++)
		{
			s += c;
		}
	}
	for (ll i = 1; i <= (s.size() - 1) / 2; i++)
	{
		if (s[i] != s[(s.size() - 1) - i + 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
