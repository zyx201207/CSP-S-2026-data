#include <bits/stdc++.h>
using namespace std;
int a[200005], book[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = (1 << 30); i >= 1; i /= 2)
	{
		int num = 0;
		for (int j = 1; j <= n; j++)
			if ((a[j] & i) != 0 && book[j] == 0)
				num++;
		if (num < m) continue;
		for (int j = 1; j <= n; j++)
			if ((a[j] & i) == 0 && book[j] == 0)
				book[j] = 1;
		ans |= i;
	}
	cout << ans;
	return 0;
}

