#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n, m;
int a[200010];
int maxn = 0;
int ca[31];
int main()
{
	freopen("and5.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= 30; i++) ca[i] = pow(2, i);
	sort(a + 1, a + n + 1, greater<int>());
	maxn = a[1];
	for (int i = 2; i <= m; i++)
	{
		maxn &= a[i];	
	}
	cout << maxn << endl;
	return 0;
} 
