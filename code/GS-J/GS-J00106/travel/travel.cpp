#include<bits/stdc++.h>
using namespace std ;
string c1 , s1 , c2 , s2 ;
int main ()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1 == c2)
	{
		cout << 1 ;
		
		for(int i = 1 ; i <= 2 ; ++ i)
		{
			if(s1[i] == s2[i])
			{
				cout << 1 ;
				if(s1[3] = 'A')
				{
					if(s2[3] = 'B')
					{
						cout << 11 ;
					}
					else
					{
						cout << 10 ;
					}
					break ;
				}
				
				else if(s1[3] = 'B')
				{
					if(s2[3] = 'A')
					{
						cout << 11 ;
					}
					else if(s2[3] == 'C')
					{
						cout << 11 ;
					}
					else
					{
						cout << 10 ;
					}
					break ;
				}
				
				else if(s1[3] = 'C')
				{
					if(s2[3] = 'B')
					{
						cout << 11 ;
					}
					else
					{
						cout << 10 ;
					}
					break ;
				}
				
				else if(s1[3] = 'D')
				{
					if(s2[3] = 'F')
					{
						cout << 11 ;
					}
					else
					{
						cout << 10 ;
					}
					break ;
				}
				
				else if(s1[3] = 'F')
				{
					if(s2[3] = 'D')
					{
						cout << 11 ;
					}
					else
					{
						cout << 10 ;
					}	
					break ;
				}
				
			}
			else cout << 0 ;
		}
	}
	else cout << "0000" ;
	return 0 ;
}
