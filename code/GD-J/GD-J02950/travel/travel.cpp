#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,s1[2],c2,s2[2];
	cin >> c1 >> s1[2] >> c2 >> s2[2];
	if (c1 <= 18 && c2 <= 18)
	{
		cout << "1";
    }
    else
    {
    	cout << "0";
	}
	if (s1[0] == s2[0]) 
	{
		if (s1[1] == s2[1])
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}	
	}
	else
	{
		cout << "0";
	}
	if (s1[2] < 4 && s2[2] < 4)
	{
		cout << "1";
	}
	else if (s1[2] > 3 && s1[2] > 3)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if (s1[2] - s2[2] == 1 or s2[2] - s1[2] == 1)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
