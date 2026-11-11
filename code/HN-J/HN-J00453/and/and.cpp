#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a = 0, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> b;
		if ( b > a)
		{
			a = b;
		}
	}
	cout << a;
	return 0;
}
