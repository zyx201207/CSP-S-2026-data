#include <bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
bool b1,b2,b3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << 1;
		b1 = 1;
	}
	else
	{
		cout << 0;
	}
	int x = (b[0] - '0') * 10 + (b[1] - '0'),y = (d[0] - '0') * 10 + (d[1] - '0');
	//cout << x << ' ' << y << ' ';
	if (x == y && b1 == 1)
	{
		cout << 1;
		b2 = 1;
	}
	else
	{
		cout << 0;
	}
	if (((b[2] >= 'D' && d[2] >= 'D') || (b[2] <= 'C' && d[2] <= 'C')) && b1 == 1 && b2 == 1)
	{
		cout << 1;
		b3 = 1;
	}
	else
	{
		cout << 0;
	}
	if (b1 == 1 && b2 == 1 && b3 == 1 && (b[2] - d[2] == 1 || d[2] - b[2] == 1))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
