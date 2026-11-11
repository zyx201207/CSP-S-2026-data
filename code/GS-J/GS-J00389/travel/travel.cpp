#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a = false;
	bool x = false;
	bool y = false;
	bool f = false;
	if(c1 == c2)
	{
		a = true;
	}
    if(a)
    {
	  if(s1[0] == s2[0] && s1[1] == s2[1])
	  {
		x = true;
	  }
    }
   if(a && x)
   {
	    if(s1[2] >= 'A' && s2[2] <= 'C')
		{
 		    y = true;	 
		}
		else if(s1[2] >= 'F' && s2[2] <= 'D')
		{
		   	y = true;
		}
	}
    if(a & x & y)
    {
    	if(s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2])
    	{
    		f = true;
		}
	}
	if(a)  cout << 1;
	else   cout << 0;
	if(x)  cout << 1;
	else   cout << 0;
	if(y)  cout << 1;
	else   cout << 0;
	if(f)  cout << 1;
	else   cout << 0;
	return 0;
}
