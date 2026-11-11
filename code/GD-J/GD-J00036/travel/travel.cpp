#include<bits/stdc++.h>
using namespace std; 

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else if(s1[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	else
	{
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))
		{
			cout<<"1100";return 0;
		}
		else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s2[2]=='F'))
		{
			cout<<"1100";return 0;
		}
		else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(abs(s1[2]-s2[2])!=1))
		{
			cout<<"1110";return 0;
		}
		else
		{
			cout<<"1111";return 0;
		}
	}
	return 0;
}
