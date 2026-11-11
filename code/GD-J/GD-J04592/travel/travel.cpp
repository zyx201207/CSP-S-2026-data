#include<bits/stdc++.h>
using namespace std;
string s, t, g, h;
bool f = false;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> t >> g >> h;
	if (s == g)
	{
		cout << '1';
	}
	else
	{
		cout << '0';
	}
	
	if (s == g && t.substr(0, 2) == h.substr(0, 2))
	{
		cout << '1';
	}
	else
	{
		cout << '0';
	}
	
	if (s == g && t.substr(0, 2) == h.substr(0, 2))
	{
		if ((t[2] == h[2]) || (t[2] == 'D' && h[2] == 'F') || (t[2] == 'F' && h[2] == 'D') || (t[2] == 'A' && (h[2] == 'B' || h[2] == 'C')) || (t[2] == 'B' && (h[2] == 'A' || h[2] == 'C')) || (t[2] == 'C' && (h[2] == 'B' || h[2] == 'A')))
		{
			cout << '1';
			f = true;
		}
		else
		{
			cout << '0';
		}
	}
	else
	{
		cout << '0';
	}
	
	if (f == false)
	{
		cout << '0';
	}
	else
	{
		if ((t[2] == 'D' && h[2] == 'F') || (t[2] == 'F' && h[2] == 'D') || (t[2] == 'C' && h[2] == 'B') || (t[2] == 'B' && (h[2] == 'A' || h[2] == 'C')) || (t[2] == 'A' && h[2] == 'B'))
		{
			cout << '1';
		}
		else
		{
			cout << '0';
		}
	}
	return 0;
}

