#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int a,x;
	string b,y;
	cin >> a >> b >> x >> y;
	if (a == x)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int pa = (b[0] - '0') * 10+(b[1] -'0');
	int pb = (y[0] - '0') * 10+(y[1] -'0');
	if (pa == pb)
	{
		cout << 1;
		
	}
	else
	{
		cout << "000";
		return 0;
	}
	if (((b[2] == 'A'|| b[2] == 'B' || b[2]== 'C')&&(y[2] == 'A'|| y[2] == 'B' || y[2]== 'C')) || ((b[2] == 'E' || b[2]== 'D')&&(y[2] == 'E'|| y[2] == 'D')))
	{
		cout << 1;
	} 
	else
	{
		cout << "00";
		return 0;
	}
	if (((b[2] - 1 == y[2])|| (b[2] + 1 == y[2])) && ((b[2] != 'C' && y[2] != 'D') || (b[2] != 'D' && y[2] != 'C')))
	{
		cout << 1;
	}
	else
	{
		cout << "0";
	}
	return 0;
}
