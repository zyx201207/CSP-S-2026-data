nclude <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N], sum[N], m;
int n;
int main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= m; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i < n; i++)
	{
		if (i * a[i + 1] - sum[i] > m)
		{
			cout << i;
			return 0;
		}
	}
	cout << n;
	return 0;
}
