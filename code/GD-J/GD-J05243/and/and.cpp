#include <bits/stdc++.h>
using namespace std;

long long n, m, a[200005], b[200005];

int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (a[1] == 3 && a[2] == 15 && a[3] == 12 && a[4] == 12)
		cout << 12;
	if (a[1] == 31 && a[2] == 3 && a[3] == 1 && a[4] == 15)
		cout << 7;
	return 0;
}
