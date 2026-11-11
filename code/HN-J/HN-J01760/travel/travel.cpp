#include<bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ss1;
	string ss2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			ss1+=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			ss2+=s2[i];
		}
	}
	if(c1==c2)
	{
		cout<<1;
		if(ss1==ss2)
		{
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
			{
				cout<<1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
				{
					cout<<1;
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
	return 0;
}
