#include<bits/stdc++.h>
using namespace std;
bool flag=0,f=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int zw1=(s1[0]-'0')*10+s1[1]-'0';
	int zw2=(s2[0]-'0')*10+s2[1]-'0';
	char fh1=s1[2];
	char fh2=s2[2];
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(zw1==zw2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(fh1<='C'&&fh2<='C'||fh1>='D'&&fh2>='D')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(fh1+1==fh2||fh2+1==fh1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
