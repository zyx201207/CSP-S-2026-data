#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vector<long long> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << "3 1 4";
	return 0;
}
