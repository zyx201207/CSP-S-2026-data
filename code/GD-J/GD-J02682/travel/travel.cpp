#include <bits/stdc++.h>
using namespace std;
string c1 , c2 , s1 , s2 , s3 , s4;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	s3 = s1.substr(0 , 2);
	s4 = s2.substr(0 , 2);
	
	if(s3 == s4)
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	s3.clear();
	s4.clear();
	s3 = s1.substr(2 , 2);
	s4 = s2.substr(2 , 2);
	char s5 = s3[0];
	char s6 = s4[0];
	if((s5 <= 'C' && s6 <= 'C') || (s5 >= 'D' && s6 >= 'D'))
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if((int)s5 + 1 == (int)s6 || (int)s6 + 1 == (int)s5)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}

