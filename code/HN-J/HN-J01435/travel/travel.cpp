#include <bits/stdc++.h>
using namespace std;
int c = 0,e = 0,d = 0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == s1)
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (c2[0] == s2[0] && c2[1] == s2[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C')
	{
		c = 1;
	}
	if (c2[2] == 'F' || c2[2] == 'D')
	{
		c = 2;
	}
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	{
		d = 1;
	}
	if (s2[2] == 'F' || s2[2] == 'D')
	{
		d = 2;
	}
	if ((c2[2] =='A' && s2[2] == 'B') || (c2[2] == 'B' && s2[2] == 'A'))
	{
		e = 1;
	}
	if ((c2[2] == 'B' && s2[2] == 'C') || (c2[2] == 'C' && s2[2] == 'B'))
	{
		e = 1;
	}
	if ((c2[2] == 'D' && s2[2] == 'F') || (c2[2] == 'F' && s2[2] == 'D'))
	{
		e = 1;
	}
	if (c == d)
	{
		cout << 1;
	}
	if (e == 1)
	{
		cout << 1;
	}
	if ( c != d)
	{
		cout << 0;
	}
	if ( e != 1)
	{
		cout << 0;
	}
	
	return 0;
	
}
