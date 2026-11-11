#include <bits/stdc++.h>
using namespace std;
long long m, a[500005], x = 0, ans = 0;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int i = 1, j = 1;
	while (j < n)
	{
		j++;
		x += (j-i) * (a[j] - a[j-1]);
		while (i < j && x > m)
		{
			x -= a[j] - a[i];
			i++;
		}
		while (j <= n && x <= m)
		{
			j++;
			x += (j-i) * (a[j] - a[j-1]);
		}
		x -= (j-i) * (a[j] - a[j-1]);
		j--;
		if (ans < j - i + 1)
		{
			ans = j - i + 1; 
		}
	}
	cout << ans;
	return 0;
 }
