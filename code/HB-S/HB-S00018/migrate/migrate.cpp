#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int x[N];
int main()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		cout << "0\n";
	}
	return 0;
}
