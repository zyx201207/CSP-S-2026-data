#include <bits/stdc++.h>
using namespace std;
//string a, string b;
char ax1, ax2, bx1, bx2;
int a4, b4;
char a3, b3;
// a4³µÏáºÅ, a1¡¢a2ÅÅºÅ, a3×ùÎ»±àÂë 
bool tongce (char a, char b)
{
	if (a == 'A' || a == 'B' || a == 'C')
	{
		if (b == 'D' || b == 'F')
		{
			return 0;
		}
	}
	if (b == 'A' || b == 'B' || b == 'C')
	{
		if (a == 'D' || a == 'F')
		{
			return 0;
		}
	}
	return 1;
}
bool xiangling (int a5, int a3, int a4, int b5, int b3, int b4)
{
	if (a5 == b5 && a4 == b4)
	{
		if ((a3 == 'A' && b3 == 'B') || (a3 == 'B' && b3 == 'C') || (a3 == 'D' && b3 == 'F')) 
		{
			return 1;
		}
		if ((b3 == 'A' && a3 == 'B') || (b3 == 'B' && a3 == 'C') || (b3 == 'D' && a3 == 'F'))
		{
			return 1;
		}
	}
	return 0;
}
int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
//	cin >> a4 >> a >> b4 >> b;
	ios::sync_with_stdio (false);
	cin.tie (0); 
	cin >> a4 >> ax1 >> ax2 >> a3 >> b4 >> bx1 >> bx2 >> b3;
//	a1 = a [0], a2 = a [1], a3 = a [2];
//	b1 = a [0], b2 = a [1], b3 = b [2];
	int a1 = ax1 - '0';
	int a2 = ax2 - '0';
	int b1 = bx1 - '0';
	int b2 = bx2 - '0';
//	cout << a4 << " " << a1 << " " << a2 << " " << a3 << " " << b4 << " " << b1 << " " << b2 << " " << b3 << "\n";
	if (a4 == b4)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	int a5 = a1 * 10 + a2;
	int b5 = b1 * 10 + b2;
//	cout << "a5=" << a5 << " " << "b5=" << b5 << "\n";
	if (a4 == b4 && a5 == b5)
	{
		cout << 1;
		if (tongce (a3, b3))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << "00";
	}
	cout << xiangling (a5, a3, a4, b5, b3, b4);
	return 0;
}
