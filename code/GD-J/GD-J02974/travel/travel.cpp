#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string p1,p2;
int g1,g2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size()-1;i++)
	{
		p1+=s1[i];
		p2+=s2[i];
	}
	if(p1!=p2)
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F')
	{
		g1=int(s1[2]);
		g1=g1+1;
	}
	else{
		g1=s1[2]-'0';
	}
	if(s2[2]=='D'||s2[2]=='F')
	{
		g2=int(s2[2]);
		g2=g2+1;
		
	}
	else{
		g2=s2[2]-'0';
	}
	if(g1>67)
	{
		if(g2<=67)
		{
			cout<<"1100";
			return 0;
		}
	}
	else{
		if(g2>67)
		{
			cout<<"1100";
			return 0;
		}
	}
	if(abs(g1-g2)!=1)
	{
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
	}
}
