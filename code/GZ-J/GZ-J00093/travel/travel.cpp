//姜玟伊 GZ-J00093 华东师范大学附属贵阳学校
#include<bits/stdc++.h>
using namespace std;
string s,s1,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>s>>b>>s1;
    if(a==b)
    {
    	cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
    for(int i=1;i=18;i++)
    {
    		if(s[0]==s1[0]&&s[1]==s1[1])
		{
			cout<<1;
			if(s[2]=='A'&&s1[2]=='B'||s[2]=='A'&&s1[2]=='C'||s[2]=='D'&&s1[2]=='E'||s1[2]=='A'&&s[2]=='B'||s1[2]=='A'&&s[2]=='C'||s1[2]=='D'&&s[2]=='E')
			{
				cout<<1;
				if(s[2]=='A'&&s1[2]=='B')
				{
					cout<<1;
				}
				else if(s[2]=='B'&&s1[2]=='C'||s[2]=='B'&&s1[2]=='A')
				{
					cout<<1;
				}
				else if(s[2]=='C'&&s1[2]=='B')
				{
					cout<<1;
				}
				else if(s[2]=='E'&&s1[2]=='D')
				{
					cout<<1;
				}
				else if(s[2]=='D'&&s1[2]=='E')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
				
			}
			else
			{
				cout<<"00";
			}
			break;
		}
		else
		{
			cout<<"000";
			break;
		}
		
	}
return 0;
 } 
