#include <iostream>
#include <algorithm>
using namespace std;

int a[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, maxn = 1;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; i++)
	{
		long long num = 0;
		for(long long j = i + 1; j <= n; j++)
		{
			num += (j - i) * (a[j] - a[j - 1]);
			if(num > m)
			{
				maxn = max(maxn, j - i);
				break;
			}
		}
	}
	cout << maxn;
	return 0;
 } 
