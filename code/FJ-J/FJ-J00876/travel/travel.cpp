#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int bz=1;
	for(int i=0;i<s1.size()-1;i++)
	{
		if(s1[i]!=s2[i])
		{
			bz=0;
		}
	}
	if(c1==c2 && bz==1)
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	
	char st;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]<='Z' && s1[i]>='A')
		{
			st=s1[i];
			break;
		}
	}
	char std;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]<='Z' && s2[i]>='A')
		{
			std=s2[i];
			break;
		}
	}
	if(c1==c2 && bz==1  && ((st=='C' && std=='B') || (st=='B' && std=='C') || (st=='A' && std=='C') ||(st=='C' && std=='A') ||(st=='A' && std=='B') ||(st=='B' && std=='A') ||(st=='D' && std=='F') ||(st=='F' && std=='D')))
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		return 0;
	}
	
	
	if(c1==c2 && bz==1  && ((st=='C' && std=='B') || (st=='B' && std=='C') || (st=='A' && std=='B') ||(st=='B' && std=='A') ||(st=='D' && std=='F') ||(st=='F' && std=='D')))
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	return 0;
}
