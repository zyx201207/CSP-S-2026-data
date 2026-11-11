#include <iostream>

using std::cin;
using std::cout;

int n, m;

int a[200005][31];

int bit[31];

int used[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		int tmp;

		used[i] = true;

		cin >> tmp;

		for(int j = 0; j <= 30; j++)
		{
			if((tmp >> j) & 1)
			{
				a[i][j] = 1;
			}

			bit[j] += a[i][j];
		}
	}

	int ans = 0;

	for(int i = 30; i >= 0; i--)
	{
		if(bit[i] < m)
		{
			continue;
		}

		for(int j = 1; j <= n; j++)
		{
			if(a[j][i] == 0 and used[j])
			{
				used[j] = false;

				for(int k = 0; k < i; k++)
				{
					bit[k] -= a[j][k];
				}
			}
		}

		ans += (1 << i);
	}

	cout << ans;
}
