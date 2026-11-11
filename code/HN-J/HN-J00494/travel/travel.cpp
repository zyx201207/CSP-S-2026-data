#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2)
		{
			s="1000";
		}
	    else
	    {
	     	s="0000";
		    cout<<"0000";
		    return 0;
	    }
		if(s1==s2)
		{
			s="1100";
	    }
		else
	    {
		    s="1000";
         	cout<<s;
		    return 0;
	    }
	cout<<s;
	return 0;
}
