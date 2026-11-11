#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, maxx(0), m;
	cin >> n >> m;
	for(int i(1); i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum;
	for(int i(n); i >= m; i--)
	{
		sum = a[i]; 
		for(int j(i); j >= i - m + 1; j--)
			sum &= a[j];
		maxx = max(maxx, sum);
	}
	cout << maxx;
	return 0;
} 
