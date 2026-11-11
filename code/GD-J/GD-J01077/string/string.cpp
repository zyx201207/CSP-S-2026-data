#include <iostream>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int f[20005];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = 0;j < a;j++)
		{
			f[i * j] = b;
		}
		a = b = 0;
	}
	int j = sizeof(f);
	bool p = true;
	for (int i = 0;i < j / 2;i++)
	{
		if (f[i] == j - i)
		{
			p = true;
		}
		else
		{
			p = false;
			break;
		}
	}
	if (p = true)
	{
		cout << "0";
	}
	return 0;
}
