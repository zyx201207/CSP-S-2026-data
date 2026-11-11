#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(c1[0]-'0')*10+(c1[1]-'0');
	a2=(c2[0]-'0')*10+(c2[1]-'0');
	if(a1!=a2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	if(a1!=a2)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	a1=(s1[2]>='A'&&s1[2]<='C'?0:1);
	a2=(s2[2]>='A'&&s2[2]<='C'?0:1);
	if(a1!=a2)
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	a1=s1[2]-'A';
	a2=s2[2]-'A';
	if(s1[2]=='F') a1--;
	if(s2[2]=='F') a2--;
	if(max(a1,a2)-min(a1,a2)!=1)
	{
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
