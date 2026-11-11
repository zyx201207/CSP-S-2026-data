#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a,b,c,d;
char x,y;
string s1,s2;
bool cmp(char m,char n)
{
		if(m=='A'&& n=='C')
			return 0;
		if(n=='A'&& m=='C')
				return 0;
		return 1;
		
}
int main()
{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		cin>>a>>s1>>b>>s2;
		if(a==b)
			cout<<1;
		else
		{
			cout<<"0000";
			return 0;
		}
		c=s1[0]-'a'+1*10+s1[1]-'a'+1;
		d=s2[0]-'a'+1*10+s2[1]-'a'+1;
		if(c==d)
			cout<<1;
		else
		{
			cout<<"000";
			return 0;
		}
		x=s1[2];
		y=s2[2];
		if(((x=='A'||x=='B'||x=='C') & (y=='A'|| y=='B'||y=='C')) || ( (x=='D'||x=='E') && (y=='D'||y=='E') ) )
			cout<<1;
		else
		{
				cout<<"00";
				return 0;
		}
		if(cmp(x,y)==1)
			cout<<1;
		else
			cout<<0;
		return 0;
}
	

