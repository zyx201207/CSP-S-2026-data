#include <bits/stdc++.h>
using namespace std;

string c1 , c2 , c3 , c4 , x , y;
int a , b , c , d , x1 , y1;

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1[0] == c3[0] && c1[1] == c3[1])
	{
		a = 1;
	}
	if (c2[0] == c4[0] && c2[1] == c4[1] && a)
	{
		b = 1;
	}
	x = c2[2];
	y = c4[2];
	if ((x == "A" || x == "B" || x == "C") && 
	(y == "A" || y == "B" || y == "C"))
	{
		c = 1;
	}
	if ((x == "D" || x == "F") && (y == "D" || y == "F"))
	{
		c = 1;
	}
	if (a == 0 || b == 0)
	{
		c = 0;
	}
	if ((x == "A" && y == "B") || 
	(x == "B" && y == "A") || 
	(x == "B" && y == "C") || 
	(x == "C" && x == "B"))
	{
		d = 1;
	}
	if ((x == "D" && y == "F") || (x == "F" && y == "D"))
	{
		d = 1;
	}
	if ((x == "C" && y == "D") || (x == "D" && y == "C"))
	{
		d = 0;
	}
	if (c == 0)
	{
		d = 0;
	}
	cout << a << b << c << d << '\n';
	
	return 0;
}
