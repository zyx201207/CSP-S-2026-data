#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
	{
	    cin >> a[i];
	    if (b[a[i] - 1] < 1) b[a[i] - 1] = i + 1;
	    else a[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
	    cout << b[i] << " ";
	}
	return 0;
}