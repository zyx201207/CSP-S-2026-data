#include <iostream>
#include <cstdio>
#include <string>
#define int long long
using namespace std;

bool aabs(char x, char y)
{
	int a = x - 'A';
	int b = y - 'A';
	int num = 0;
	if (a - b >= 0)
	{
		num = a - b;
	}
	else
	{
		num = (a - b) * -1;
	}
	if (num == 1 || (x == 'D' && y == 'F') || (x == 'F' && y == 'D'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

signed main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool q1 = false, q2 = false, q3 = false;
	if (c1 == c2){
		q1 = true;
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	string u1, u2;
	u1 += s1[0];
	u1 += s1[1];
	u2 += s2[0];
	u2 += s2[1];
	if (q1 && u1 == u2)
	{
		q2 = true;
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	if (q1 && q2 && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')))
	{
		q3 = true;
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (q1 && q2 && q3 && aabs(s1[2], s2[2]))
	{
		cout << 1;
	}
	else
	{
		cout << 0; 
	}
	return 0;
}
