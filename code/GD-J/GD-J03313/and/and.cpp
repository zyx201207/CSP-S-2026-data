#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200100];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	long long x = a[n];
	for (int i = n-1; i > n-m; i--)
		x &= a[i];
	cout << x;
	return 0;
}
