#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	string c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	bool flag = 1, flag1 = 1;
	for (int i = 0; i < 2; i++)
	{
		if (c1[i] == c3[i])
		{
			continue;
		}
		else
		{
			flag = 0;
			cout << 0;
			break;
		}
	}
	if (flag == 1)
	{
		cout << 1;
	}
	for (int i = 0; i < 2; i++)
	{
		if (c2[i] == c4[i])
		{
			continue;
		}
		else
		{
			flag1 = 0;
			cout << 0;
			break;
		}
	}
	if (flag1 == 1)
	{
		cout << 1;
	}
	if ((c2[2] <= 'C') && (c4[2] <= 'C'))
	{
		cout << 1;
	}
	else if ((c2[2] >= 'D') && (c4[2] >= 'D'))
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0;
		return 0;
	}
	if (abs(c2[2] - c4[2]) == 1)
	{
		cout << 1;
	}
	else if ((c2[2] == 'D' && c4[2] == 'F') || (c2[2] == 'F' && c4[2] == 'D'))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
    return 0;	
}
