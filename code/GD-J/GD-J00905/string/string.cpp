#include <bits/stdc++.h>
using namespace std;
int n;
long long h;
long long a1[200005];
long long a[200005];
char c1[200005];
char c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a1[i]);
		h += a1[i];
		cin >> c1[i];
	}
	long long cnt = 0, mid = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt > h / 2)
		{
			a[i + 2] = a1[i];
			c[i + 2] = c1[i];
			continue;
		}
		cnt += a1[i];
		if(cnt > h / 2)
		{
			a[i] = (h / 2 - (cnt - a1[i]));
			c[i] = c1[i];
			mid = i + 1;
			a[i + 1] = 0;
			a[i + 2] = a1[i] - a[i];
			if(h % 2 == 1)
			{
				a[i + 2] -= 1;
			}
			c[i + 2] = c1[i];
		}
		else
		{
			a[i] = a1[i];
			c[i] = c1[i];
		}
	}
	long long ans = 0, x;
	int l = 1, r = n + 2;
	while(l <= r)
	{
		while(a[l] == 0 && l + 1 <= mid)
		{
			l++;
		}
		while(a[r] == 0 && r - 1 >= mid)
		{
			r--;
		}
		if(l == mid && r == mid)
		{
			cout << ans << '\n';
			return 0;
		}
		if(c[l] != c[r])
		{
			ans += min(a[l], a[r]);
		}
		x = min(a[l], a[r]);
		a[l] -= x;
		a[r] -= x;
		if(a[l] == 0)
		{
			l++;
		}
		if(a[r] == 0)
		{
			r--;
		}
	}
	return 0;
}
