#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;

int x[maxn];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		int cnt = 0;
		cout << cnt << endl; 
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				int l = (x[j] - x[i]) / (j - i);
				int y = d / l;
				int z = (j - i) % y + 1;
				if (z == 2)
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
