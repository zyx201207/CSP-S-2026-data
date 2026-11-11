#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2[5],s2[5];
int main()
{
	cin>>c1;

	for(int i=1;1<=3;i++)
	{
		cin>>c2[i];
	}
	cin>>s1;
	for(int i=1;1<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1==s1)
	{
		cout<<"1";
		if(c2[1]==s2[1]&&c2[2]==s2[2])
		{
			cout<<"1";
			if((c2[3]=="D"&&s2[3]=="F")||(c2[3]=="F"&&s2[3]=="D")||(c2[3]=="A"&&s2[3]=="B")||(c2[3]=="A"&&s2[3]=="C")||(c2[3]=="B"&&s2[3]=="C")||(c2[3]=="B"&&s2[3]=="A")||(c2[3]=="C"&&s2[3]=="A")||(c2[3]=="C"&&s2[3]=="B"))
			{
				cout<<"1";
				if((c2[3]=="D"&&s2[3]=="F")||(c2[3]=="F"&&s2[3]=="D")||(c2[3]=="A"&&s2[3]=="B")||(c2[3]=="B"&&s2[3]=="C")||(c2[3]=="B"&&s2[3]=="A")||(c2[3]=="C"&&s2[3]=="B"))
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}

	return 0;
 }
