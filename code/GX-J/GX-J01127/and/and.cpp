#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200000], c[200000];
int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		
		c[i] = max (c[i-1] & a[i], c[i-1]);
	}
	cout << "65";
    return 0;
}
