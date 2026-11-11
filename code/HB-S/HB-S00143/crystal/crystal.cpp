#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long mid;
	if (n % 2 == 0)
	{
		if (a[n / 2] < a[n / 2 + 1]) mid = n / 2;
		else if (a[n / 2] > a[n / 2 + 1]) mid = n / 2 + 1;
		else mid = n / 2;
	}
	else if (n % 2 == 1) mid = n / 2 + 1;
	for (int i = mid - 1; i >= 1; i--)
	{
		if (m >= a[mid] - a[i]) 
		{
			m -= (a[mid] - a[i]);
			a[i] = a[mid];
		}
		else break;
	}	
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == a[mid]) cnt++;
	}	
	cout << cnt;
	return 0;
}
