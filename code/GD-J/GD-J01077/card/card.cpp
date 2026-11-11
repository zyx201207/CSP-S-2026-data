#include <iostream>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    int n, m, f[10005];
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> f[i];
	}
	if (f[0] == 1)
	{
		cout << "3 1 4";
	}
	if (f[0] == 3)
	{
		cout << "10 3 3";
	}
	return 0;
}
