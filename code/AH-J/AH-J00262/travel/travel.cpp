#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	} 
	
	string a1,b1,a2,b2;
	a1=s1[1];
	a2=s2[2];
	b1=s1[2];
	b2=s2[2];
	
	
	if(a1==a2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	
	
	if(b1<="C" && b1>="A" && b2<="C" && b2>="A")
	{
		cout<<1;
		if(b1=="A" && b2=="C")
		{
			cout<<0;
			return 0;
		}
		else if(b2=="C" && b1=="A")
		{
			cout<<0;
			return 0;
		}
		else
		{
			cout<<1;
			return 0;
		}
	}
	else if(b1<="F" && b1>="D" && b2<="F" && b2>="D" && b1!="E" && b2!="E")
	{
		cout<<11;
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}
