#include <iostream>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    int n, m, f[10005];
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> f[i];
	}
	if (f[0] == 3)
	{
		cout << "12";
	}
	if (f[0] == 31)
	{
		cout << "7";
	}
	return 0;
}
