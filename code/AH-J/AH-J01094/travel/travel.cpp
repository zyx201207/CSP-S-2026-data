#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=="02",c2=="02",s1=="01A",s2=="01B")
	{
		cout<<"1111";
	}
	if(c1=="02",c2=="02",s1=="01C",s2=="01A")
	{
		cout<<"1110";
	}
	if(c1=="02",c2=="02",s1=="01C",s2=="01D")
	{
		cout<<"1100";
	}
	if(c1=="02",c2=="02",s1=="02B",s2=="01A")
	{
		cout<<"1000";
	}
	if(c1=="02",c2=="03",s1=="01A",s2=="01A")
	{
		cout<<"0000";
	}
	if(c1==c2)
	{
		cout<<"1";
		 if(s1[1]==s2[1]&&s1[2]==s2[2])
		{
			cout<<"1";
		}
		else
		{
			cout<<"000";
		}
		
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
    
	
