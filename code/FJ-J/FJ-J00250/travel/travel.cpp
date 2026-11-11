#include<bits/stdc++.h>

using namespace std;

string s,c,ss,cc;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	string p=s.substr(0,2),pp=ss.substr(0,2),w=s.substr(2),ww=ss.substr(2);	
	if(p!=pp)
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	if((w=="A"&&ww=="B")||(w=="A"&&ww=="C")||(w=="B"&&ww=="C")||(w=="B"&&ww=="A")||(w=="C"&&ww=="A")||(w=="C"&&ww=="B")||(w=="F"&&ww=="D")||(w=="D"&&ww=="F"))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((w=="A"&&ww=="B")||(w=="B"&&ww=="C")||(w=="B"&&ww=="A")||(w=="C"&&ww=="B")||(w=="F"&&ww=="D")||(w=="D"&&ww=="F"))
	{
		cout<<"1";
	}
	else
	{	
		cout<<"0";
	}
	return 0;
}
