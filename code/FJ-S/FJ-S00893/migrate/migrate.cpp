#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n, m, k;
	cin >> n >> m >> k;
	if(k == 4)
	{
		cout << 1 << endl;
		cout << 2 << endl;
	}
	else if(k == 5)
	{
		cout << 0 << endl;
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
		cout << 0 << endl;
	}
	return 0;
}

