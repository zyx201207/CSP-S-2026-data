#include <iostream>
#include <cstring>
using namespace std;
int n, x, ans;
string c, y;
string a1[200005], a2[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		for (int i = 1; i <= x; i++)
		{
			c += y;
		}
	}
	int m = c.length();
	for (int i = 1; i <= m / 2; i++)
	{
		a1[i] = c[i-1];
		a2[i] = c[m-i];
		if (a1[i] != a2[i])
			ans++;
	}
	cout << ans;
	return 0;
}
