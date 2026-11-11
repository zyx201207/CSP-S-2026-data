#include <bits/stdc++.h>
using namespace std;
string r;
string x;
string a,b;
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin >> a;
	cin >> r;
	cin >> b;
	cin >> x;
	if (a == b)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if (r[0] == x[0] && r[1] == x[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if (r[2] >='A' && r[2] <='C' && x[2] >='A' && x[2]<='C')
	{
		cout << 1;
	}
	else
	{
		if (r[2] >='D' && r[2] <='E' && x[2] >='D' && x[2]<='E')
		{
			cout << 1;
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			cout << 0;
			return 0;
		}
	}
	if (r[2] > x[2])
	{
		if ((r[2] - x[2]) == 1)
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
		if ((x[2] - r[2]) == 1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	return 0;
}


