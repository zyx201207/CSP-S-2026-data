#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		bool flag=true;
	    if(s1[1]==s2[1]&&s1[0]==s2[0])
	    {
		   cout<<'1';
		   if((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A'))
		   {
		      cout<<'1';
			  flag=false;
			  if(abs((int)s1[2]-(int)s2[2])==1) cout<<'1';
			  else cout<<'0';
		    }
	     	if((s1[2]<='F'&&s1[2]>'C')&&(s2[2]<='F'&&s2[2]>'C'))
		    {
			   cout<<"11";
			   flag=false;
		    } 
		     if(flag)
		    {
			   cout<<"00";
		    } 
		}
		else cout<<"000";
    }
    else cout<<"0000";
	return 0;
 } 
