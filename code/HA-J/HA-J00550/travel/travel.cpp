#include<bits/stdc++.h>
#define itn int
#define cotu cout
#define fro for
using namespace std;
itn a,b,c,d;
string x,y;
char m,n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> x >> b >> y;
	c = x[0]*10+x[1];
	d = y[0]*10+y[1];
	n = x[2],m = y[2];
	if (a == b)
	{
		cout << "1";
		if (c == d)
		{
			cout << "1";	
			if((n == 'D' && m == 'F') || (n == 'F' && m == 'D'))
			{
				cout << "11";
				return 0;
			}	
			if((n == 'C' || n == 'B' || n == 'A') && (n != 'F' && m != 'D'))
			{
				cout << "1";
				if ((n == 'C' && m == 'B') || (n == 'B' && m == 'A') || (n == 'B' && m == 'C') || (m == 'B' && n == 'A'))
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}	
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
//02 01A 02 01B

//02 01C 02 01A

//02 01C 02 01D

//02 02B 02 01A

//02 01A 03 01A


