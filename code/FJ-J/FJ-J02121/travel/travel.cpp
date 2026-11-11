#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
for(int i=1;i<=1;i++)
{

	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
	    break;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		break;
	}
	if (s1[2]>64&&s1[2]<68)
	{	if(s2[2]>64&&s2[2]<68)
		{
			cout<<"1";
       	}
       	else
       	{
       		cout<<"00";
       		break;
		}
    }
    else
    {
	    if (s1[2]>67&&s1[2]<71)
		{	if(s2[2]>67&&s2[2]<71)
			{
				cout<<"1";
	       	}
	    }
	    else
	    {
	    	cout<<"00";
		}
	}
    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)
    {
    	cout<<"1";
	}
	else
	{
		if(s2[2]==70&&s1[2]==68)
		{
			cout<<"1";
		}
		else if(s2[2]==68&&s1[2]==70)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}

}
return 0;
} 
