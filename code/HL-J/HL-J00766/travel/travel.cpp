#include <bits/stdc++.h>
using namespace std;
char c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,ck1,ck2,ck3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2  >> c3 >> c4 >> c5  >> c6 >> c7  >> c8 >> c9 >> c10;
	if(c1==c6&&c2==c7)
	{
		cout << 1;
		if(c3==c8&&c4==c9)
		{
			cout << 1;
			if((c5>='A'&&c5<='C'&&c10>='A'&&c10<='C')||(c5>='D'&&c5<='E'&&c10>='D'&&c10<='E'))
			{
				cout << 1;
				if((c5 == c10+1)||(c10==c5+1))
				cout << 1;
				else
				cout << 0;
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