#include <iostream>
#include <cstring>
using namespace std ;

int main ()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	string c1 , s1 , c2 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	int len1 = c1.size()-1 ;
	if (c1 == c2)
	{
		cout << 1 ;
		string a = s1.substr(0 , 2) ;
		string b = s2.substr(0 , 2) ;
		if (a == b)
		{
			cout << 1 ;
			string x = s1.substr(2) ;
			string y = s2.substr(2) ;
			if(x[0] - 'A'>= 0 && x[0] - 'A' <= 2)
			{
				if (y[0] - 'A' >= 0 && y[0] - 'A' <= 2)
				{
					cout << 1 ;
					if (abs((y[0]-'A') - (x[0] - 'A')) == 1)
					{
						cout << 1 ;
					}
					else cout << 0 ;
				}
				else cout << "00" ;
			}
			else
			{
				if (y[0] >= 'D' && y[0] <= 'F') cout<< "11" ;
				else cout << "00" ;
			}
		}
		else 
		{
			for (int i = 1 ; i <= 3 ; i++)
			{
				cout << 0 ;
			}
		}
	}
	else
	{
		for (int i = 1 ; i <= 4 ; i++)
		{
			cout << 0 ;
		}
	}
	return 0 ;
}
