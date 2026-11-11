#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+="1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	string p1,p2;
	p1+=s1[0];p2+=s2[0];
	p1+=s1[1];p2+=s2[1];
	if(p1==p2)
	{
		ans+="1";
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	bool fg1=0,fg2=0,fg3=0,fg4=0;
	char ch1=s1[2],ch2=s2[2];
	int a1=ch1-'A'+1,b1=ch2-'A'+1;
	if(ch1=='A'||ch1=='B'||ch1=='C') fg1=1;
	if(ch2=='D'||ch2=='F') fg2=1;
	if(ch2=='A'||ch2=='B'||ch2=='C') fg3=1;
	if(ch1=='D'||ch1=='F') fg4=1;
	if(fg1==1&&fg2==1)
	{
		cout<<"1100";
		return 0;
	}
	if(fg3==1&&fg4==1)
	{
		cout<<"1100";
		return 0;
	}
	else
	{
		ans+="1";
	}
	if(ch1=='D'&&ch2=='F')
	{
		cout<<"1111";
		return 0;
	}
	if(abs(a1-b1)==1)
	{
		ans+="1";
	}
	if(abs(a1-b1)!=1)
	{
		ans+="0";
	}
	cout<<ans;
	return 0;
}
