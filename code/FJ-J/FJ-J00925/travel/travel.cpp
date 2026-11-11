#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a=true,b=true,c=true,d=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c2[2]=='F')
		c2[2]='E';
	if(s2[2]=='F')
		s2[2]='E';
	for(int i=0;i<2;i++)
		if(c1[i]!=s1[i])
			a=false;
	if(!a)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
		if(c2[i]!=s2[i])
			b=false;
	if(!b)
	{
		cout<<"1000";
		return 0;
	}
	if((c2[2]>'C'&&s2[2]>'C')||(c2[2]<='C'&&s2[2]<='C'))
		c=true;
	else
		c=false;
	if(!c)
	{
		cout<<"1100";
		return 0;
	}
	if(abs(c2[2]-s2[2])!=1)
		d=false;
	if(!d)
		cout<<"1110";
	else
		cout<<"1111";
	return 0;		
}
