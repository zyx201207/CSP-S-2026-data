#include <bits/stdc++.h>
using namespace std;

string a, b, c, d;

int main()
{
	freopen("travel.in", "r", stdin); 
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> a >> b >> c >> d;
	if (a != c)
	{
		cout << "0000";
		return 0;
	}
	cout << '1';
	if (b[0] == d[0] && b[1] == d[1])
	{
		cout << '1';
		if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C')
		{
			if (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')
			{
				cout << '1';
				if (abs(int(b[2]) - int(d[2])) == 1)
				{
					cout << '1';
					return 0;
				}
				cout << '0';
				return 0;
			}
			cout << "00";
			return 0;
		}
		if (d[2] == 'D' || d[2] == 'F')
		{
			cout << '1';
			if (abs(int(b[2]) - int(d[2])) == 1)
			{
				cout << '1';
				return 0;
			}
			cout << '0';
			return 0;
		}
		cout << "00";
		return 0;
	}
	cout << "000";
	return 0;
}
