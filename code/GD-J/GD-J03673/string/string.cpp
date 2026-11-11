#include <bits/stdc++.h>
using namespace std;
long long n, cnt = 0, k, m = 0, num = 0;
char a[200005];
int main()
{
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	char s;
	for (int i = 1; i <= n; i++)
	{
		cin >> k >> s;
		num += k;
		for (long long j = 1; j <= k; j++)
		{
			a[++m] = s;
		}
	}
	long long mid = m / 2 + 1;
	for (long long i = 1; i <= mid; i++)
	{
		if (a[i] != a[m + 1 - i]) cnt++;
	}
	cout << cnt;
	return 0;
}
