#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	string chp1=s1.substr(0,2),chp2=s2.substr(0,2);
	if(c1==c2 && chp1==chp2)
	{
		cout<<1;
	}
	else cout<<0;
	int ss1=s1[2],ss2=s2[2];
	if(ss1==68) ss1=71;
	else if(ss1==69) ss1=72;
	if(ss2==68) ss2=71;
	else if(ss2==69) ss2=72;
	if(c1==c2 && chp1==chp2 && abs(ss1-ss2)<=2) cout<<1;
	else cout<<0;
	if(c1==c2 && chp1==chp2 && abs(ss1-ss2)==1) cout<<1;
	else cout<<0;
	return 0;
}
