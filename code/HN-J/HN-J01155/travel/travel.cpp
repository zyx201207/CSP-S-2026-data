#include <bits/stdc++.h>
using namespace std;
bool flag = true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (b[1] == d[1])
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if ((b[2] <= 'C' && d[2] <= 'C')||(b[2] >= 'D' && d[2] >= 'D'))
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if (abs(d[2] - b[2])== 1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
} 
