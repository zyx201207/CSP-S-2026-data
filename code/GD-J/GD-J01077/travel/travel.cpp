#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	bool f = true;
	if (a == c)
	{
		f = true;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1])
	{
		f = true;
	}
	else
	{
		cout << "1000";
		return 0;
	}
	if ((a[2] == 'A' && a[2] == 'B') || (a[2] == 'A' && a[2] == 'C') || (a[2] == 'B' && a[2] == 'A') || (a[2] == 'B' && a[2] == 'C') || (a[2] == 'C' && a[2] == 'A') || (a[2] == 'C' && a[2] == 'B') || (a[2] == 'E' && a[2] == 'F') || (a[2] == 'F' && a[2] == 'E'))
	{
		f = true;
	}
	else
	{
		cout << "1100";
		return 0;
	}
	if ((a[2] == 'A' && a[2] == 'B') || (a[2] == 'B' && a[2] == 'A') || (a[2] == 'B' && a[2] == 'C') || (a[2] == 'C' && a[2] == 'B') || (a[2] == 'E' && a[2] == 'F') || (a[2] == 'F' && a[2] == 'E'))
	{
		f = true;
	}
	else
	{
		cout << "1110";
		return 0;
	}
	if (f = true)
	{
		cout << "1111";
		return 0;
	}
}
