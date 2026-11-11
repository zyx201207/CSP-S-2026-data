#include <bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc)
	{
		cout<<"0000";
		return 0;
	}
	else{
		ans+="1";
	}
	char r=rz[0],x=xz[0],p=rz[2],q=xz[2];
	r+=rz[1],x+=xz[1];
	if(r!=x)
	{
		cout<<"1000";
		return 0;
	}
	else{
		ans+="1";
	}
	if((p>='A'&&p<='C'&&q>='A'&&q<='C')||(p>='D'&&p<='F'&&q>='D'&&q<='F'))
	{
		ans+="1";
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(abs(p-q)!=1)
	{
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
	}
	return 0;
}
