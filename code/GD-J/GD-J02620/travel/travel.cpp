#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a==c)
	{
		cout << 1;
		if (b.substr(0,2)==d.substr(0,2))
		{
			cout << 1;
			char bb=b.size()-1,dd=d.size()-1;
			if (('A'<=b[bb] && b[bb]<='C' && 'A'<=d[dd] && d[dd]<='C') || ('D'<=b[bb] && b[bb]<='E' && 'D'<=d[dd] && d[dd]<='E'))
			{
				cout << 1;
				int x=b[bb]-'A',y=d[dd]-'A';
				if (abs(x-y)==1)
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
