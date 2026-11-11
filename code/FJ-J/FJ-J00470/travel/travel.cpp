#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char pd(char x1,char x2)
{
	if(x1=='A')
	{
		if(x2=='B'||x2=='C')
		return '1';
	}
	else if(x1=='B')
	{
		if(x2=='A'||x2=='C')
		return '1';
	}
	else if(x1=='C')
	{
		if(x2=='A'||x2=='B')
		return '1';
	}
	else if(x1=='D')
	{
		if(x2=='F')
		return '1';
	}
	else if(x1=='F')
	{
		if(x2=='D')
		return '1';
	}
	else
	return '0';
}
bool td(char x1,char x2)
{
	if(x1=='A')
	{
		if(x2=='B')
		return '1';
	}
	else if(x1=='B')
	{
		if(x2=='A'||x2=='C')
		return '1';
	}
	else if(x1=='C')
	{
		if(x2=='B')
		return '1';
	}
	else if(x1=='D')
	{
		if(x2=='F')
		return '1';
	}
	else if(x1=='F')
	{
		if(x2=='D')
		return '1';
	}
	else
	return '0';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<'1';
			if(pd(s1[2],s2[2])=='1')
			{
				cout<<'1';
				if(td(s1[2],s2[2])=='1')
				{
					cout<<'1';
				} 
				else
				cout<<'0';
			}
			else
			cout<<"00";
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000";
	return 0;
} 
