#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	char seat[6] = {'A', 'B', 'C', 'X', 'D', 'F'};
	cin >> c1 >> s1 >> c2 >> s2;
	
	int t1, t2;
	for(int i=0 ; i<6 ; i++)
	{
		if(seat[i] == s1[2]) t1 = i;
		if(seat[i] == s2[2]) t2 = i;
	}
	
	if(c1 == c2) 
	{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			if(t1 <= 2 && t2 <= 2 || t1 >= 4 && t2 >= 4)
			{
				cout << "1";
				if(t1-t2 == 1 || t1-t2 == -1)
				{
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";

	return 0;
}
