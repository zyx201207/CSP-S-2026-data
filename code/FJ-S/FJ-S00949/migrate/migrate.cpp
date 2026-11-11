#include <iostream>
using namespace std;
int c, t;
int n, d;
long long x[2000005];
int main()
{
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	
	while (t--)
	{
		cin >> n >> d;
		if (c == 11 || c == 12)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> x[i];
			}
			int ch = x[2] - x[1];
			int f = d / ch + 1;
			
			return 0;
		}
	}
	return 0;
}
