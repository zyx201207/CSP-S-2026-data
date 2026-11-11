#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	string a="";
	a+=s1[0]+s1[1];
	string b="";
	b+=s2[0]+s2[1];
	if(a==b)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||('D'<=s1[2]&&'D'<=s2[2]))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	char x=s1[2],y=s2[2];
	if(abs(x-y)==1)
		cout<<1;
	else
		cout<<0;
	return 0;
} 
