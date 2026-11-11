#include <bits/stdc++.h>
using namespace std;

long long n, m, cnt = 0;


int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	long long a[n];
	cnt = n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == a[i-1])
		{
			cnt--;
		}
	}
	cout << cnt;
	return 0;
}
