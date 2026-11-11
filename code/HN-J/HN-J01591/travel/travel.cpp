#include <bits/stdc++.h>
using namespace std;

int check (char a, char b, int type)
{
	int x = a - 'A';
	int y = b - 'A';
	if (type == 1)
	{	
		if (x <= 2 && y <= 2) return 1;
		else return 0;
	}
	else
	{
		if (x > y) swap(x, y);
		if (y == x + 1) return 1;
		else return 0; 
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ca, sa, cb, sb;
	cin >> ca >> sa >> cb >> sb;
	
	if (ca == cb) cout << 1;
	else 
	{
		cout << "0000";
		return 0;
	}
	
	if (sa[0] == sb[0] && sa[1] == sb[1]) cout << 1;
	else 
	{
		cout << "000";
		return 0;
	}
	
	if (check(sa[2], sb[2], 1)) cout << 1;
	else 
	{
		cout << "00";
		return 0;
	}
	
	if (check(sa[2], sb[2], 2)) cout << 1;
	else 
	{
		cout << "0";
		return 0;
	}
	return 0;
} 
