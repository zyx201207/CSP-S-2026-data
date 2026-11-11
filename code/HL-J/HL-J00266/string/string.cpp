#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
int a[N];
char c[N];
LL res;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i] >> c[i];
	
	int i = 1, j = n;
	while (i < j)
	{
		if (a[i] > a[j])
		{
			if (c[i] == c[j])
			{
				a[i] -= a[j];
				j -- ;
			}
			else
			{
				a[i] -= a[j];
				res += a[j];
				j -- ;
			}
		}
		else
		{
			if (c[i] == c[j])
			{
				a[j] -= a[i];
				i ++ ;
			}
			else
			{
				a[j] -= a[i];
				res += a[i];
				i ++ ;
			}
		}
	}
	
	cout << res << endl;
	return 0;
}
