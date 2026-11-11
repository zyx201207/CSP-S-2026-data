#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f=0,ok=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')&&c1==c2)
	{
		f=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[2]<='C'&&s2[2]<='C'&&f==1)
	{
		ok=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(ok==1&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
