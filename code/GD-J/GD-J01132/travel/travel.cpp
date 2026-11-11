#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool vis = 0, vis1 = 0, vis2 = 1, vis3 = 0;//vischexiang vis1tongyipai 1
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1])
	{
		vis = 1;
		cout << "1";
	} 
	if (!vis)
	{
		cout << "0";
	}
	if (vis && s1[0] == s2[0] && s1[1] == s2[1])
	{
		vis1 = 1;
		cout << "1";
	}
	if (!vis1)
	{
		cout << "0";
	}
	if (vis && vis1)
	{
		int R = 0, L = 0;//0shixia
		if (s1[2] == 'D' || s1[2] == 'F')
		{
			R = 1;
		}
		if (s2[2] == 'D' || s2[2] == 'F')
		{
			L = 1;
		}
		if (R == L)
		{
			vis3 = 1;
			cout << "1";
		}
	}
	if (!vis3)
	{
		cout << "0";
	}
	int xR = int(s1[2] - 'A'), xX = int(s2[2] - 'A');
	if (abs(xR - xX) == 1 && (xR != 2 && xX != 3))
	{
		if (xR != 3 && xX != 2 && vis && vis1 && vis3)
		{
			vis2 = 0;
			cout << "1";
		}	
	}
	if (vis2)
	{
		cout << "0";
	}
	return 0;
} 
