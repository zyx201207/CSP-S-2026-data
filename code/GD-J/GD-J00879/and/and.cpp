#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int main()
{
	freopen("ans.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int cnt = a[n];
	for (int i = n - 1; i >= n - m + 1; i--) cnt = cnt & a[i];
	cout << cnt;
	return 0;
}
