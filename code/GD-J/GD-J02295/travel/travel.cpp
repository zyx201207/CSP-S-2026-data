#include<bits/stdc++.h>
using namespace std;

int n1,n2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1==n2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000"<<endl;
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='c')||(s1[2]>='D'&&s2[2]<='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00"<<endl;
		return 0;
	}
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
 } 
