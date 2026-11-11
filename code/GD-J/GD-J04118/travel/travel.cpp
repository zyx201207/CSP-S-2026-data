#include<iostream>
#include<fstream>
using namespace std;
int c1 , c2;
string s1 , s2;
int ABS(int n)
{
	if(n < 0) return -n;
	return n;
}
int main()
{
	freopen("travel.in" , "r" , stdin); 
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << 1;
			char temp1 = s1[2] , temp2 = s2[2];
			if(temp1 >= 'A' && temp1 <= 'C' && temp2 >= 'A' && temp2 <= 'C')
			{
				cout << 1;
				if(temp1 >= 'A' && temp1 <= 'C' && temp2 >= 'A' && temp2 <= 'C' && ABS(int(temp1) - int(temp2)) == 1) cout << 1;
				else cout << 0;
			}
			else if(s1[0] == s2[0] && s1[1] == s2[1] && temp1 >= 'D' && temp1 <= 'F' && temp2 >= 'D' && temp2 <= 'F')
			{
				cout << 11;
				return 0;
			}
			else cout << "00";
		}
		else cout << "000";
		
	}
	else cout << "0000";
	
	return 0;
}
