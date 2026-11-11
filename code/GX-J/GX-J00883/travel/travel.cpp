#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int c1 , c2 ;
string s1 , s2 ;
int flag = 0 ;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2 ;
	{
	if(c1 == c2)
		cout << 1 ;
		else cout << 0 ;
		flag=1 ;
		{
			if(flag!=1) cout << 0 ;
			else 
			{
				if (s1 == s2)
				cout << 1 ; 
			}
			cout << 0 ;
		}
	}	
	
	
	return 0;
}
