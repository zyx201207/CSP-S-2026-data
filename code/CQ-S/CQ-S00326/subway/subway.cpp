#include <iostream>
using namespace std;

int a[505][500005], t[505][500005];
int k[505], x[100005], y[100005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k[i]; j++)
		{
			sum = sum + a[i][j] + t[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}
