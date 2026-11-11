#include <bits/stdc++.h>
using namespace std;
#define ll long long

string a, b, c, d;

bool check(char x, char y)
{
	if (x == 'D' && y == 'F')
		return true;
	if (x == 'F' && y == 'D')
		return true;
	if (x == 'A' && y == 'B')
		return true;
	if (x == 'B' && y == 'A')
		return true;
	if (x == 'B' && y == 'C')
		return true;
	if (x == 'C' && y == 'B')
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1])
		{
			cout << "1";
			if ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D'))
			{
				cout << "1";
				if (check(b[2], d[2]))
				{
					cout << "1";
					return 0;
				}
				else
				{
					cout << "0";
					return 0;
				}
			}
			else
			{
				cout << "00";
				return 0;
			}
		}
		else
		{
			cout << "000";
			return 0;
		}
	}
	else
	{
		cout << "0000";
		return 0;
	}
	return 0;
} 
