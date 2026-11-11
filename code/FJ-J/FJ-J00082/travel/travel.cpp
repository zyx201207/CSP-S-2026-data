#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool b, b2, b0;
bool check1(char x, char y)
{
	if(x > y)
	{
		swap(x, y);
	}
	if(x == 'A' && y == 'C')
	{
		return 1;
	}else if(x == 'A' && y == 'B')
	{
		return 1;
	}else if(x == 'B' && y == 'C')
	{
		return 1;
	}else if(x == 'D' && y == 'F')
	{
		return 1;
	}
	return 0;
}
bool check2(char x, char y)
{
	if(x > y)
	{
		swap(x, y);
	}
	if(x == 'A' && y == 'B')
	{
		return 1;
	}else if(x == 'B' && y == 'C')
	{
		return 1;
	}else if(x == 'D' && y == 'F')
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	string c1t;
	string c2t;
	c1t = s1[0] + s1[1];
	c2t = s2[0] + s2[1];
	if(c1 == c2)
	{
		b0 = 1;
		cout << 1;
	}else{
		cout << 0;
	}
	if(c1t == c2t && b0 == 1)
	{
		cout << 1;
		b = 1;
	}else
	{
		cout << 0;
	}
	if(b == 1 && check1(s1[2], s2[2]))
	{
		cout << 1;
		b2 = 1;
	}else
	{
		cout << 0;
	}
	if(b2 == 1 && check2(s1[2], s2[2]))
	{
		cout << 1;
	}else
	{
		cout << 0;
	}
	return 0;
}
