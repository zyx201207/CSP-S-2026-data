#include <bits/stdc++.h>
using namespace std;

int c1,c2,l1,l2;
string s1,s2,s11,s22;
char le[3] = {'A','B','C'};

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else 
	{
		cout << "0000";
		return 0;
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1])  
	{
		cout << 1;
		
		for (int i = 0; i <= 2; i++)
		{
			if (s1[2] == le[i])
			{
				l1 = 1;
				//cout << " ";
				s11 = le[i];
			}
			if (s2[2] == le[i])
			{
				l2 = 1;
				//cout << " ";
				s22 = le[i];
			}
			if (l1 == 1 && l2 == 1) 
			{ 
				cout << 1;
				if (s11 == "B" || s22 == "B") cout << 1;
				else cout << 0;
				return 0;
			} 
		}
		if (l1 != l2) 
		{
			cout << "00";
			return 0;
		}
		if (l1 != 1 && l2 != 1)
		{
			if (l1 == 0 && l2 == 0) 
			{
				cout << 11;	
				return 0;
			}
			else cout << 0;
		}
	}
	else cout << "000"; 
	return 0;
}
