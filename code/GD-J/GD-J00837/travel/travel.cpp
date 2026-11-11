#include <bits/stdc++.h>
using namespace std;

int main()
{
     freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	 int a,b,c,d;
	 char e,f;
	 cin >> a >> b >> e>> c >> d >> f;
	if(a==c)
	{
		cout << "1";
		if(b==d)
	    {
		    cout << "1";
		    if((e<='c'&&f<='c')||(e>='d'&&f>='d'))
		    {
		    	cout << "1";
		    	if((e<='c'&&(e-f==1||f-e==1))||(e>='d'&&(e-f==2||f-e==2)))
		    	{
		    		cout << "1";
				}
				else
				{
					cout << "0";
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
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
} 
