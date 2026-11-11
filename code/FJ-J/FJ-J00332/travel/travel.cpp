#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	 string c1, s1, c2, s2;
	 cin >> c1 >> s1 >> c2 >> s2;
	 int a1 = (c1[0] - '0') * 10 + c1[1] - '0';
	 int a2 = (c2[0] - '0') * 10 + c2[1] - '0';
	 if (a1 != a2)
	 {
	 	cout << "0000";
	 }
	 else
	 {
	 	cout << "1";
	 	int num1 = (s1[0] - '0') * 10 + s1[1] - '0';
	 	int num2 = (s2[0] - '0') * 10 + s2[1] - '0';
	 	if (num1 == num2)
	 	{
	 		cout << "1";
	 		if (s1[2] != 'C' && s2[2] != 'D')
			{
			 	if (abs(s1[2] - s2[2]) == 1)
				{
				 	cout << "11";
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
		 	return 0;
		}
	 } 
	return 0;
 } 
