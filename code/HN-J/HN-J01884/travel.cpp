#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	//freopen ("travel.in","r",stdin);
	//freopen ("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if ((c1[0] - '0') * 10 + c1[1] == (c2[0] - '0') * 10 + c2[1])
	{
		cout << "1";
		if ((s1[0] - '0') * 10 + s1[1] - '0' == (s2[0] - '0') * 10 + s2[1] - '0')
	    {
	    	cout << "1";
	    	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
	        {
		        if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C' && s2[2] != s1[2])
	    	    {
	        		cout <<"1";
	        		if (s1[2] == 'B' || s2[2] == 'B')
	        		{
	        			cout << "1";
					}
					else
					{
						cout << '0';
					}
	    	    }
    		    else
	        	{
	        		cout << "0" << "0";
		        }
	        }
	        else
	        {
		        if (s2[2] == 'D' || s2[2] == 'F' && s2[2] != s1[2])
		        {
		        	cout << "1" <<"1";
		        }
		        else
		        {
		        	cout <<"0" << "0";
		        }
	        }
	    }
    	else
	    {
    		cout << "0" << "0" << "0";
    	}
	}
	else
	{
		cout << "0" << "0" << "0" <<"0";
	}
	
	
	return 0;
} 
