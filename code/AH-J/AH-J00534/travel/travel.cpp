
#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
char a, b;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m >> a >> x >> y >> b;
	if (n != x)
	{
		cout << "0000";
		return 0;
	}
	cout << '1';
	if (m != y)
	{
		cout << "000";
		return 0;
	}
	cout << '1';
	if (a == 'A')
	{
		if (b == 'B')
		{
			cout << "11";
		}
		else if (b == 'C')
		{
			cout << "10";
		}
		else
		{
			cout << "00";
		}
	}
	else if (a == 'B')
	{
		if (b == 'A' || b == 'C')
		{
			cout << "11";
		}
		else
		{
			cout << "00";
		}
	}
	else if (a == 'C')
	{
		if (b == 'B')
		{
			cout << "11";
		}
		else if (b == 'A')
		{
			cout << "10";
		}
		else
		{
			cout << "00";
		}
	}
	else if (a == 'D')
	{
		if (b == 'F')
		{
			cout << "11";
		}
		else
		{
			cout << "00";
		}
	}
	else
	{
		if (b == 'D')
		{
			cout << "11";
		}
		else
		{
			cout << "00";
		}
	}
	return 0;
}
