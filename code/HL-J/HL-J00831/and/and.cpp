#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in", "r");
	freopen("and.out", "w");
	int n, m , a[10000000];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << a[n];
	return 0;
}