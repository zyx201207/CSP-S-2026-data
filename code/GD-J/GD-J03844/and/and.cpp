#include <bits/stdc++.h>
using namespace std;

long long a[200005], q[200005];

int main()
{
	freopen("card1.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long maxn = -1e9, cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == m)
		{
			cnt++;
			q[cnt] = a[i - m + 1];
			for (int j = i - m + 1; j <= m; j++)
			{
				q[cnt] = q[cnt] and a[j];
			}
			cout << q[cnt] << " ";
		}
		else if (i > m)
		{
			cout << (q[cnt] and a[i]) << " ";
			cnt++;
			q[cnt] = q[cnt - 1] and a[i];
		}
	}
	return 0;
}
