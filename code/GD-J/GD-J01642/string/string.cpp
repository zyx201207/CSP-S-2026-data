#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
long long n, ans;
pair<long long, char> a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	long long l = 2, r = n, rest = a[1].first;
	char rest_l = a[1].second;
	bool cc = 0;
	while (l <= r)
	{
		if (rest > 0)
		{
			if (cc == 0)
			{
				if (a[r].second == rest_l)
				{
					if (a[r].first > rest)
					{
						rest = a[r].first - rest;
						cc = 1;
						l++;
					}
					else if (a[r].first < rest)
					{
						rest -= a[r].first;
						r--;
					}
					else
					{
						rest = a[l].first;
						rest_l = a[l].second;
						cc = 0;
						l++, r--;
					}
				}
				else
				{
					if (a[r].first < rest)
					{
						rest -= a[r].first;
						ans += a[r].first;
						r--; 
					}
					else if (a[r].first > rest)
					{
						ans += rest;
						rest = a[r].first - rest;
						cc = 1;
						rest_l = a[r].second;
						l++;
					}
					else
					{
						ans += rest;
						rest = a[l].first;
						rest_l = a[l].second;
						cc = 0;
						l++, r--;
					}
				}
			}
			else
			{
				if (a[l].second == rest_l)
				{
					if (a[l].first > rest)
					{
						rest = a[l].first - rest;
						cc = 0;
						r++;
					}
					else if (a[l].first < rest)
					{
						rest -= a[l].first;
						l--;
					}
					else
					{
						rest = a[l].first;
						rest_l = a[l].second;
						cc = 0;
						l++, r--;
					}
				}
				else
				{
					if (a[l].first < rest)
					{
						rest -= a[l].first;
						ans += a[l].first;
						l--; 
					}
					else if (a[l].first > rest)
					{
						ans += rest;
						rest = a[l].first - rest;
						cc = 0;
						rest_l = a[l].second;
						r++;
					}
					else
					{
						ans += rest;
						rest = a[l].first;
						rest_l = a[l].second;
						cc = 0;
						l++, r--;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
