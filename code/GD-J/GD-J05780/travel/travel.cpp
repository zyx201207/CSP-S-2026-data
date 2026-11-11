#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out,"W",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	long long e=(c1[0]-'0')*10+(c1[1]-'0'),f=(c2[0]-'0')*10+(c2[1]-'0');
	if(e!=f)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0')
	{
		cout<<"1";
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
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
		cout<<"00";
	}
	long long a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	if(((a+1==b)||(a-1==b)||(a==b))&&((s1[2]-'0'-1==s2[2]-'0')||(s1[2]-'0'+1==s2[2]-'0')||(s1[2]==s2[2])))
	{
		if(s1[2]=='C')
		{
			if(s2[2]=='D')
			{
				cout<<"0";
				return 0;
			}
		}
		if(s1[2]=='D')
		{
			if(s2[2]=='C')
			{
				cout<<"0";
				return 0;
			}
		}
		if(a+1==b||a-1==b)
		{
			if((s1[2]-'0'-1==s2[2]-'0')||(s1[2]-'0'+1==s2[2]-'0'))
			{
				cout<<"0";
				return 0;
			}
		}
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
