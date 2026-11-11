#include<iostream>
using namespace std;
long long n, a[200005], head = 1, tail;
char c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	tail = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	while (head < tail)
	{
		if (a[head] == a[tail])
		{
			if (c[head] != c[tail])
			{
				ans += a[tail];
			}
			head++;
			tail--;
		}
		if (a[head] < a[tail])
		{
			if (c[head] != c[tail])
			{
				ans += a[head];
			}
			a[tail] -= a[head];
			head++;
		}
		if (a[head] > a[tail])
		{
			if (c[head] != c[tail])
			{
				ans += a[tail];
			}
			a[head] -= a[tail];
			tail--;
		}
	}
	cout << ans;
	return 0;
}
