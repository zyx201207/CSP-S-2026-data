#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char s11,s22;
	cin>>c1>>s1>>s11>>c2>>s2>>s22; 
	if(c1!=c2)
	cout<<"0000";
	else if(s1!=s2)
	cout<<"1000";
	else if(s22<='C'&&s22>='A'&&s11<='C'&&s11>='A')
	{
		if(max((int)s22,(int)s11)-min((int)s22,(int)s11)==1)
		cout<<"1111";
		else
		cout<<"1110";
	}
	else if(s22<='D'&&s22>='F'&&s11<='D'&&s11>='F')
	{
		cout<<"1111";
	}
	else
	cout<<"1100";
	return 0;
}
