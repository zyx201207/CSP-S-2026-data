#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	flag=true;
	for(int i=0;i<2;i++)
		if(c1[i]!=c2[i])
			flag=false;
	if(flag)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	flag=true;
	for(int i=0;i<2;i++)
		if(s1[i]!=s2[i])
			flag=false;
	if(flag)
		cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(flag)
	{
		if((s1[2]=='A' && s2[2]=='B') || (s2[2]=='A' && s1[2]=='B'))
			cout<<"11";
		else if((s1[2]=='B' && s2[2]=='C') || (s2[2]=='B' && s1[2]=='C'))
			cout<<"11";
		else if((s1[2]=='A' && s2[2]=='C') || (s2[2]=='A' && s1[2]=='C'))
			cout<<"10";
		else if((s1[2]=='F' && s2[2]=='D') || (s2[2]=='F' && s1[2]=='D'))
			cout<<"11";
		else
			cout<<"00";
	}
	return 0;
}
