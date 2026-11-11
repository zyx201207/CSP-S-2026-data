//GZ-J00517，石浩辰，北京师范大学贵阳附属中学 
#include <bits/stdc++.h> 
using namespace std;
string c1 , s1 , c2 , s2 , s; 
char a , b;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)   
	{
		s[0]= '1';
	}
	else  s[0] = '0';
	if(s1[1] == s2[1] && s1[0] == s2[0])  
	{
		s[1] = '1';
    }
    else s[1]= '0';
    a = s1[2] , b = s2[2];
    if((a < 'D' && b < 'D')||(a >= 'D' && b >= 'D'))
    {
    	s[2] = '1';
    	if(a < 'D')
    	{
    		if (a == 'B' || b == 'B')
    		{
    			s[3] = '1';
			}
			else s[3] = '0';
		}
		else s[3]= '1';
	}
	else  s[2] = '0' , s[3] = '0';
	cout << s[0] << s[1] << s[2] << s[3] ;
	return 0;
}
