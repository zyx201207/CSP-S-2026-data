#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	int c, t, u[1000005],v[1000005],min1 = 10000, min2 = 10000;
	for (int i = 1; i <= t; i++)
	{
		cin >> u[i] >> v[i];
		min1 = min(min1, u[i]);
		min2 = min(min2, v[i]);
	}
	cout << min1 << endl << min2;
	return 0;
} 
