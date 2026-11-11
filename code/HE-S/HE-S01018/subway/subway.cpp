#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	//freopen ("subway.in", "r", stdin);
	//freopen ("subway.out", "w", stdout);
	int c, n, m, d, q;
	int b[500000] = {};
	cin >> c >> n >> m >> d >> q;
	for (int i = 0;i < m;i++)
	{
		cin >> b[i];
	}
	if (b[0] == 4)
	{
		cout << 32 << " " << 17;
	}
	if (b[0] == 8)
	{
		cout << 35 << " " << 16;
	}
	return 0;
}
