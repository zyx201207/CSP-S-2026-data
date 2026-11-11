#include <bits/stdc++.h>
using namespace std;
bool a,b,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	{
		cout<<"1";
		b=1;
	}
	else
	{
		cout<<"0";
	}
	
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&b==1)
	{
		cout<<"1";	
		a=1;
	}
	else
	{
		cout<<"0"; 
	}
	if(((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'||c4[2]=='F'))||((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C'))&&a==1)
	{
		cout<<"1";
		c=1;
	}
	else
	{
		cout<<"0";
	}
	
	if((c2[2]=='A'||c4[2]=='A')&&(c2[2]=='B'||c4[2]=='B')&&c==1)
    {
	    cout<<"1";
    }
    else if((c2[2]=='B'||c4[2]=='B')&&(c2[2]=='C'||c4[2]=='C')&&c==1)
   {
    	cout<<"1";
   }
    else if((c2[2]=='D'||c4[2]=='D')&&(c2[2]=='F'||c4[2]=='F')&&c==1)
    {
	    cout<<"1";
    }
    else
    { 
	    cout<<"0";
    }
	return 0;
 } 
