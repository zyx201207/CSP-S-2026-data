#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i)
	{
		stack<int> q;
		for (int j = i; j <= n; ++j)
		{
			for (int k = 1; k <= i; ++k) if (a[k] == a[j]) q.pop();
			q.push(a[j]);
		}
		for (int j = 1; j <= q.size(); ++j) for (int i = 1; i <= m; ++i) if (a[j] == i) b[i]++;
	}
	for (int i = 1; i <= m; ++i) cout << b[i];
	return 0;
}
