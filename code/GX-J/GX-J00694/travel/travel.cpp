#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		a += "1";
		if (s1[0] == s2[0] && s1[1] == s2[1])
	    {
		    a += "1";
		    bool flag;
		    if ((s1[2]=='D' && s1[2]=='F') || (s1[2]=='F' && s2[2]=='D'))
		    {
				flag = true;
			    a += "1";
		    }
		    else if (s1[2]=='D' || s1[2]=='F')
		    {
				flag = false;
				a += "00";
			}
			else{
				flag = true;
				a += "1";}
			if (flag == true && (s1[2] == 'D'||s2[2] == 'D'))
	            {
		            a += "1";
	            }
	            else if(s1[3] == 'B' || s2[2] == 'B')
	            {
					a += "1";
			    }
			    else
			    {
					a+="0";}
	    }
	    else
	    {
			a += "000";}
	}
	else
	{
		a += "0000";
	}
	cout << a;
	return 0;
}
