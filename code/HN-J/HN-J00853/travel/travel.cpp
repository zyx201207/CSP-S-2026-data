#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
char n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!='0') a+=10;
	if(c2[0]!='0') b+=10;
	int i=0,j=0;
	i=c1[1]-'0';
	j=c2[1]-'0';
	a+=i;
	b+=j;
	i=0;
	j=0;
	if(a==b) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	a=0;
	b=0;
	if(s1[0]!='0') a+=10;
	if(s2[0]!='0') b+=10;
	i=s1[1]-'0';
	j=s2[1]-'0';
	a+=i;
	b+=j;
	if(a==b) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	n=s1[2];
	m=s2[2];
	if((n=='A'||n=='B'||n=='C')&&(m=='A'||m=='B'||m=='C')) cout<<1;
	else if((n=='D'||n=='F')&&(m=='D'||m=='F'))
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((n=='A'||n=='C')&&(m=='A'||m=='C')) cout<<0;
	else cout<<1;
	return 0;
}
