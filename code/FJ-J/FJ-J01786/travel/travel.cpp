#include <bits/stdc++.h>

using namespace std;

int r[4];
int x[4];

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (s1 == s2)
	{
		return 0;
	}
	
	else if (c1 == "01" || c1 == "16" || c2 == "01" || c2 == "16")
	{
		return 0;
	}
	
	else if (c1 == c2)
	{
		for (int i = 0; i < 2; i ++ )
		{
			r[i] = s1[i];
		}	
		r[2] = s1[2];
		if (r[0] + r[1] > 106 || r[2] > 70 || r[2] == 69)
		{
			return 0;
		}
		
		for (int i = 0; i < 2; i ++ )
		{
			x[i] = s2[i];
		}
		x[2] = s2[2];
		if (x[0] + x[1] > 106 || x[2] > 70 || x[2] == 69)
		{
			return 0;
		}
		
		cout << '1' ;
		for (int i = 1; i < 2; i ++ )
		{
			if (x[i] == r[i])
			{
				cout << '1';
				if (r[2] <= 67 && x[2] <= 67)
				{
					cout << '1';
					if (r[2] == 65 && x[2] == 66)
					{
						cout << '1';
					}
				
					else if (r[2] == 66 && x[2] == 65)
					{
						cout << '1';
					}
		
					else if (r[2] == 67 && x[2] == 66)
					{
						cout << '1';
					}
		
					else if (r[2] == 66 && x[2] == 67)
					{
						cout << '1';
					}
			
					else cout << '0';
				}
		
				else if (r[2] > 67 && x[2] > 67)
				{
					cout << '1';
					if (r[2] == 68 && x[2] == 70)
					{
						cout << '1';
					}
		
					else if (r[2] == 70 && x[2] == 68)
					{
						cout << '1';
					}
			
					else cout << '0';
				}
				
				else cout << "00";
				
				return 0;
			}
			
			else 
			{
				for (int i2 = i; i < 4; i ++ )
				{
					cout << '0';
				}
				
				return 0;
			}
		}
	}
	
	else 
	{
		cout << "0000";
		return 0;
	}
	
	return 0;
}
