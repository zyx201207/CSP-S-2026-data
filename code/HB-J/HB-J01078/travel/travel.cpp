#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	int c1 , s1 , c2 , s2;
	char r , x;
	cin >> c1 >> s1 >> r;
	cin >> c2 >> s2 >> x;
	if(c1 == c2)
	{
		cout << 1;
		if(s1 == s2)
		{
			cout << 1;
			if((r == 'A' || r == 'B' || r == 'C') && (x == 'A' || x == 'B' || x == 'C'))
			{
				cout << 1;
				if((r == 'A' && x == 'B') || (r == 'B' && x == 'A')||
				   (r == 'B' && x == 'C') || (r == 'C' && x == 'B'))
				   {
					   cout << 1;
				   }
				else
				{
					cout << 0;
				}
			}
			else if((r == 'D' || r == 'E') && (x == 'D' || x == 'E'))
			{
				cout << 11;
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
