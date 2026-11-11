#include<bits/stdc++.h>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int seat1=int(s1[0]-'0')*10+int(s1[1]-'0');
	int seat2=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(seat1==seat2)
		cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(seat1!=seat2||s1[2]=='C'&&s2[2]=='D')
	{
		cout<<0<<0;
		return 0; 
	}
	else if(s1[2]-1==s2[2]||s1[2]+1==s2[2]||s1[2]=='C'&&s2[2]=='A')
		cout<<1;
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]&&seat1==seat2)
		cout<<1;
	else
		cout<<0;
	return 0;
}

