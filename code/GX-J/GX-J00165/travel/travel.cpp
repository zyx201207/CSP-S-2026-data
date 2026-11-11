#include <bits/stdc++.h>
using namespace std;

string x,y;
char a,b,c,d,e,f;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> a >> b >> c;
	cin >> y >> d >> e >> f;
	if(x != y)
	{
		cout << "0000";
	}
	else
	{
		cout << 1;
		if(a != d || b != e)
		{
			cout << "000";
		}
		else
		{
			cout << 1;
			if((c == 'D' && f != 'F') || (f == 'D' && c != 'F'))
			{
				cout << "00";
			}
			else if((c == 'F' && f != 'D') || (f == 'F' && c != 'D'))
			{
				cout << "00";
			}
			else
			{
				cout << 1;
				long long A = c - 'A',B = f - 'A';
				if(abs(A - B) == 1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
	}
	return 0;
}
