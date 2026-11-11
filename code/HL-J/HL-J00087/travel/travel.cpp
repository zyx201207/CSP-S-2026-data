#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool f=0,f1=0,f2=0; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<1;
		f1=1;
	}
	else
	{
		cout<<0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]&&f1==1)
	{
		cout<<1;
		f2=1;
	}
	else
	{
		cout<<0;
	}
	if(s[2]+ss[2]<=133&&abs(s[2]-ss[2])<=2&&f2==1||s[2]+ss[2]==137&&f2==1)
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
	}
	if(int(ss[2])==s[2]+1&&f==1||ss[2]+1==int(s[2])&&f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
