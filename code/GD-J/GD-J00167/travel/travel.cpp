#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string cara, carb;
string ta, tb;
bool cmp(char a, char b)
{
	if (abs(a - b) > 2)
	{
		return 0;
	}
	if (abs(a - b) == 2)
	{
		if (a == 'C' && b == 'A' || a == 'A' && b == 'C')
		{
			return 1;
		}
		return 0;
	}
	if (abs(a - b) == 1)
	{
		if (a == 'C' && b == 'D' || a == 'D' && b == 'C')
		{
			return 0;
		}
		return 1;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cara >> ta >> carb >> tb;
	if (cara != carb)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << "1";
	}
	if (ta[0] == tb[0] && ta[1] == tb[1])
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if (cmp(ta[2], tb[2]))
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if (abs(ta[2] - tb[2]) != 1 || ta[2] == 'C' && tb[2] == 'D' || tb[2] == 'C' && ta[2] == 'D')
	{
		cout << "0";
	}
	else
	{
		cout << "1";
	}
	return 0;
}
