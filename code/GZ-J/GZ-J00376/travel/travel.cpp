//GZ-J00376 喻东志 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
bool r1=false;
bool r2=false;
bool r3=false;
bool r4=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		r1=true;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(r1==true&&(s1[0]==s2[0])&&(s1[1]==s2[1]))
	{
		r2=true;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(r2==true&&r1==true&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
	{
		r3=true;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))
	{
		r4=true;
	}
	if(r3=true&&r2==true&&r1==true&&r4==false&&abs(s1[2]-s2[2])==1)
	{
		cout<<1<<'\n';
	}
	else
	{
		cout<<0<<'\n';
	}
	return 0;
}
