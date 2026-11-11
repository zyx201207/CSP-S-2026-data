#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n, m;
vector<ll> a(200005); 
bool cmp(ll a, ll b)
{
	return a > b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		sort(a.begin() + 1, a.begin() + n + 1, cmp);
		cout << a[1];
		return 0;
	}
	else if(m == 2)
	{
		ll max_n = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j) continue;
				max_n = max(max_n, a[i] & a[j]);
			}
		}
		cout << max_n;
		return 0;
	}
	else if(m == n)
	{
		ll res = a[1];
		for(int i = 2;i <= n;i++)
		{
			res = res & a[i];
		}
		cout << res;
		return 0;
	}
	else
	{
		sort(a.begin() + 1, a.begin() + n + 1, cmp);
		ll res = a[1];
		for(int i = 2;i <= m && i <= n;i++)
		{
			if((res & a[i]) > (a[i] & a[i + 1]))
				res = res & a[i];
			else
				m++;
		}
		cout << res;
		return 0;
	}

	return 0;
}
