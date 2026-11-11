#include <bits/stdc++.h>
using namespace std;

int x, y, u, v;
char a, b;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> u >> a >> y >> v >> b;
	if(x == y)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(x == y && u == v)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(x == y && u == v && (a <= 'C' && b <= 'C' || a >= 'D' && b >= 'D'))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(x == y && u == v && (a <= 'C' && b <= 'C' || a >= 'D' && b >= 'D') && abs(a - b) == 1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	cout << '\n';
	return 0;
}
