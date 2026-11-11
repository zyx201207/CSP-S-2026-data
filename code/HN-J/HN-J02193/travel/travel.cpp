#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a1=0,a2=0,a3=0,a4=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	a1=1;
	else
	a1=0;
	if(short(s1[0]*10+s1[1])==short(s2[0]*10+s2[1]))
	a2=1;
	else
	a2=0;
	if(a2==1) 
	{
		if(char(s1[2])>char(s2[2]))
		{
			if(char(s1[2])<'D')
			a3=1;
			else
			{
				if(char(s1[2])=='F'&&char(s2[2])>'C')
				a3=1;
				else
				a3=0;
			}
		}
		else
		{
			if(char(s2[2])<'D')
			a3=1;
			else
			{
				if(char(s2[2])=='F'&&char(s1[2])>'C')
				a3=1;
				else
				a3=0;
			}
		}
	}
	else
	a3=0;
	if(a3==1)
	{
		if(char(s2[2])-char(s1[2])==1||char(s1[2])-char(s2[2])==1)
		a4=1;
		else
		a4=0;
	}
	else
	a4=0;
	cout<<a1<<a2<<a3<<a4<<endl;
	return 0;
}
