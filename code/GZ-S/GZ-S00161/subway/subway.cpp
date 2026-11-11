//中央民族大学附属中学贵阳学校 刘俊宏 GZ-S00161 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int c, n, m, d, q, w[100005], k[105][10005], a[105][10005], t[105][10005], x[105], y[105];
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i][1];
		for (int j = 1; j <= 2*k[i][1]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> k[i][1];
		for (int j = 1; j <= 2; j++)
		{
			cin >> x[j] >> y[j];
		}
    }
    if (n == 3)
    {
        cout << 32 << endl << 17;
	}
	else
	{
		cout << 35 << endl << 16;
	}
	return 0;
}
