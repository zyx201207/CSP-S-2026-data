#include<iostream>
using namespace std;

int C, T;
long long n, d, x[2000010], c, ans, a[2000010];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--)
	{
		cin >> n >> d;
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		c = x[2] - x[1];
		for(int i = 4; i <= n; i += 2)
		{
			if(d < ((i / 2 + 1) * c) && d >= (i / 2 * c))
			{
				ans += n - i + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
