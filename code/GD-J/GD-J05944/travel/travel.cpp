#include<bits/stdc++.h> 
using namespace std;
string c1,c2,s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c2!="16"&&c1!="19"&&c2!="20")
	{
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<'1';
			if(s1[2]-'A'<3&s2[2]-'A'<3)
			{
				cout<<'1';
				if(s1[2]-s2[2]==0||s2[2]-s1[2]==0)
				{
					cout<<'1';
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
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
}
