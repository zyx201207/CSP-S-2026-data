#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], cnt[300005];
stack<ll> s;
bool f[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (ll i = 1; i < n; i++)
	{
		memset(f, 0, sizeof(f));
		while (!s.empty())
		{
			s.pop();
		}
		for (ll j = i; j <= n; j++)
		{
			if (!f[a[j]])
			{
				f[a[j]] = 1;
				s.push(a[j]);
			}
			else
			{
				while(s.top() != a[j])
				{
					f[s.top()] = 0;
					s.pop();
				}
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (f[i])
			{
				cnt[i]++;
			}
		}
	}
	cnt[a[n]]++;
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
} 
