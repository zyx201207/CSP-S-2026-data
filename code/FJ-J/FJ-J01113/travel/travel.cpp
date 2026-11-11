#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if(a1 == a2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	
	
	if(b1[1] == b2[1] && b1[0] == b2[0])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	
	bool f = 0;
	if(b1[1] == b2[1] && b1[0] == b2[0])
	{
		if(b1[2] <= 'C' && b2[2] <= 'C')
		{
			cout << 1;
			f = 1;
		}
		else if(b1[2] >= 'D' && b2[2] >= 'D')
		{
			cout << 1;
			f = 1;
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
	
	
	
	if(f == 1 && int(b1[2]) + 1 == int(b2[2]))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
