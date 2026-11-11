//中央民族大学附属中学贵阳学校 刘俊宏 GZ-J00227
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, y;
	string m, x;
	cin >> n >> m >> y >> x; 
	if (n == y)
	{
		cout << "1";
		if (m[0] == x[0]&&m[1] == x[1])
		{
			cout<< "1";
			if (m[2] == 'A')
			{
			    if (x[2] == 'B')
			    {
			    	cout << "11";
				}
				else if (x[2] == 'C')
				{
					cout << "10";
				}
			}
			else if (m[2] == 'B')
		    {
		    	if (x[2] == 'A')
		    	{
		    		cout << "11";
				}
				else if (x[2] == 'C')
				{
					cout << "11";
				}
			}
			else if (m[2] == 'C')
			{
				if (x[2] == 'A')
				{
					cout << "10";
				}
				else if (x[2] == 'B')
				{
					cout << "11";
				}
			}
			else if (m[2] == 'D')
			{
				if (x[2] == 'F')
				{
					cout << "11";
				}
			}
			else if (m[2] == 'F')
			{
				if (x[2] == 'D')
				{
					cout <<"11";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
