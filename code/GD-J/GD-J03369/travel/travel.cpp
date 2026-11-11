#include <iostream>
#include <set>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool _1 = false;
	if (c1 == c2)
	{
		cout << 1;
		_1 = true;
	}
	else
	{
		cout << 0;
	}
	
	bool _2 = false;
	if (_1 && (s1[0] == s2[0]) && (s1[1] == s2[1]))
	{
		cout << 1;
		_2 = true;
	}
	else
	{
		cout << 0;
	}
	
	int _3 = 0;
	set<char> l2, l1;
	l1.insert('A');
	l1.insert('B');
	l1.insert('C');
	
	l2.insert('D');
	l2.insert('F');
	if (_2)
	{
		if (l1.count(s1[2]) && l1.count(s2[2]))
		{
			_3 = 1;
			cout << 1;
		}
		else if (l2.count(s1[2]) && l2.count(s2[2]))
		{
			_3 = 2;
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	
	char x = s1[2], y = s2[2];
	if (_3 == 1)
	{
		if ((x - y == 1) || (x - y == -1))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else if (_3 == 2)
	{
		if ((x - y == 2) || (x - y == -2))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	
	return 0;
} 
