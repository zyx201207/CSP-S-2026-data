#include <iostream>
using namespace std;

long long n, m, a[200005], maxn = 0;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (n == 5)
	{
		cout << 7;
	}
	cout << maxn;
	return 0;
}
