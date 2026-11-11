#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!="01"&&c1!="16"&&c2!="01"&&c2!="16")
	{
		cout<<1;
		if( s1[0]==s2[0] && s1[1]==s2[1] )
		{
			cout<<1;
			if(s1[2]-'A'<3&&s1[2]-'A'>=3)
			{
				cout<<00;
				return 0;
			}
			if(s1[2]-'A'>=3&&s1[2]-'A'<3)
			{
				cout<<00;
				return 0;
			}
			if(abs((s1[2]-'0')-(s2[2]-'0'))==1)
			{
				cout<<11; 
			}
			else
			{
				cout<<10;
									}						
		}
		else
		{
			cout<<000;
		}
		
		
	}
	else
	{
		cout<<0000;
	}

	
}
