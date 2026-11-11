#include <bits/stdc++.h>
using namespace std;
int c1 = 0;
string s1 = "";
int c2 = 0;
string s2 = "";
int bj = 0;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		for(int i=0;i<2;i++)
		{
			if(s1[i]==s2[i])
			{
				bj=1;
			}
			else
			{
				bj=0;
			}
		}
		if(bj==1)
		{
			cout<<"1";
			
			if(s1[2]-'0'>=('A'-'0')&&s1[2]-'0'<=('C'-'0')&&s2[2]-'0'>=('A'-'0')&&s2[2]-'0'<=('C'-'0'))
			{
				
				cout<<"1";
				if(((s1[2]-'0')-(s2[2]-'0'))==1||((s2[2]-'0')-(s1[2]-'0'))==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if(s1[2]-'0'==('D'-'0')&&s2[2]-'0'==('F'-'0'))
			{
				cout<<"11";
				
			}
			else if(s1[2]-'0'==('F'-'0')&&s2[2]-'0'==('D'-'0'))
			{
				cout<<"11";
				
			}
			else
			{
				//cout<<"/n";
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
	
	return 0;
}
