#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
long long ans;
string s;
pair<int, char> a[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d%s", &a[i].first, &a[i].second);

	int l = 1, r = n;

	while (l <= r && l <= n && r >= 1)
	{
		int n1 = a[l].first, n2 = a[r].first;
		char c1 = a[l].second, c2 = a[r].second;

		if (c1 != c2)
			ans += min(n1, n2);

		if (n1 > n2)
			a[r].first = 0, a[l].first -= n2, --r;

		if (n2 > n1)
			a[l].first = 0, a[r].first -= n1, ++l;

		if (n1 == n2)
			a[l].first = a[r].first = 0, ++l, --r;
	}

	cout << ans;

	return 0;
}
