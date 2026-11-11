#include<iostream>
#include<cstdio>
using namespace std;
int getnum()
{
	char x, y;
	cin >> x >> y;
	return (x - '0') * 10 + (y - '0');
}
int getc()
{
	char c;
	cin >> c;
	return (c - 'A');
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b, c, d, x, y;
	a = getnum();
	b = getnum();
	x = getc();
	c = getnum();
	d = getnum();
	y = getc();
	if(a != c)
		cout << "0000";
	else if(b != d)
		cout << "1000";
	else if((x < 3) ^ (y < 3))
		cout << "1100";
	else if(x < 3 && max(x, y) == 2 && min(x, y) == 0)
		cout << "1110";
	else
		cout << "1111";
	return 0;
}
