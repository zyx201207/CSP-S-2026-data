#include<bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		cout<<"1";
	}
	else
	{
			cout<<"0";
	}
	if(s1[3]>="A"&&s1[3]<="c")&&s2[3]>="A"&&s2[3]<="c")
	{
		cout<<"1";
		if(s1[3]+1==s2[3]||s1[3]-1==s2[3])
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else if((s1[3]>="D"&&s1[3]<="F")&&(s2[3]>="D"&&s2[3]<="F"))
	{
		cout<<"1";
		if(s1[3]+2==s2[3]||s1[3]-2==s2[3])
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	
	return 0;
}

