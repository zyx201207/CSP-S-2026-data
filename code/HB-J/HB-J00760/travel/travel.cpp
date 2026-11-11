#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(c2[1]==s2[1]&&c2[0]==s2[0])
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((c2[2]!='F'&&c2[2]!='D'&&s2[2]!='F'&&s2[2]!='D')||(c2[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&c2[2]=='D'))
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(c2[2]+1==s2[2]||s2[2]+1==c2[2])
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		return 0;
	}
}
