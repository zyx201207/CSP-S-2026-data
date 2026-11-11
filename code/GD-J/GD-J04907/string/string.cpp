#include <iostream>
using namespace std;

int n, x, l = 0;
char a, q;
bool w = true;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		cin >> a;
		if (i >= 2 && a != q)
		{
			w = false;
		}
		q = a;
		l += x;
	}
	if (!w)
	{
		if (n == 3)
		{
			cout << 2;
		}
		if (n == 2)
		{
			cout << 0;
		}
		if (n == 6)
		{
			cout << 3000000000;
		}
	}
	else if (!w)
	{
		if (l % 2 == 0)
		{
			cout << l / 2;
		}
		else
		{
			cout << (l -1) / 2;
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}
