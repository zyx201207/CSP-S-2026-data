#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if (a != c)
		cout << "0000" << endl;
	else
	{
		cout << "1";
		int e = (b[0] - '0') * 10 + (b[1] - '0');
		int f = (d[0] - '0') * 10 + (d[1] - '0');
		if (e != f)
			cout << "000" << endl;
		else
		{
			cout << "1";
			int bb = 0,dd = 0;
			if (b[2] == 'F')
				b[2] = 'E';
			if (d[2] == 'F')
				d[2] = 'E';
			if (b[2] <= 'C')
				bb = 0;
			else
				bb = 1;
			if (d[2] <= 'C')
				dd = 0;
			else
				dd = 1;
			if (bb == dd)
			{
				if (abs(b[2] - d[2]) == 1)
					cout << "11" << endl;
				else
					cout << "10" << endl;
			}
			else
				cout << "00" << endl;
		}
	}
	return 0;
} 
