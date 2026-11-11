#include <bits/stdc++.h>
using namespace std;
string as, bs;
int ac, bc;
int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin >> ac >> as >> bc >> bs;
	string a = as.substr(0, 2), b = bs.substr(0, 2);
	
	
	if (ac == bc)
	{
		cout<< 1;
		if (ac == bc && a == b)
		{
			cout<< 1;
			if ((as[2] <= 'C' && bs[2] <= 'C') || (as[2] > 'C' && bs[2] > 'C'))
			{
				cout << 1;
				int x = abs(as[2] - bs[2]);
				if (x == 1)
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
	}
	return 0;
}
/*
02 01A 02 01B

*/
