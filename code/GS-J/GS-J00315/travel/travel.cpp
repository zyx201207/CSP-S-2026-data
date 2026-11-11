#include<bits/stdc++.h>
#define endl'\n'
using namespace std;

int main()
{
///	freopen("travel.in","r","stdin");
///	freopen("travel.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=0;i<c1.size()-1&&i<c2.size()-1;i++)
	{
		if(c1==c2)
		{
			for(int j=0;j<s1.size()-1&&j<s2.size()-1;j++)
			{
				if('1'<=s1[j]<='18'&&'1'<=s2[j]<='18'&&s1[j]==s2[j])
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
				if('A'<=s1[j]<='C'&&'A'<=s2[j]<='C')
				{
					cout<<"11";
				}
				else
				{
					cout<<"10";
				}
			    if('D'<=s1[j]<='F'&&'D'<=s2[j]<='F'&&s1[j]!=s2[j]!='E')
				{
					cout<<"11";
				}
				else
				{
					cout<<"10";
				}
			}
		}
		else
		{
			cout<<"000";
			break;
		}
	
	}
	return 0;
}
