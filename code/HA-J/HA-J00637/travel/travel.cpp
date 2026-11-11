#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a+='1';
	}
	else 
	{
		a+='0000';
		cout<<a;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		a+='1';
	}
	else 
	{
		a+='000';
		cout<<a;
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
    	a+='1';
    else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
    {
    	a+='1';
    }
    else 
	{
		a+='00';
		cout<<a;
		return 0;
	}
    if(s1[2]-s2[2]+'0'=='1'||s2[2]-s1[2]+'0'=='1')
      a+='1';
    else a+='0';
    cout<<a;
	return 0;
}
