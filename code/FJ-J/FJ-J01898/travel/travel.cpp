#include <bits/stdc++.h>
using namespace std;
int sp1,sp2;
int c1,c2;
char ss1,ss2;
string s1,s2;
int t1=0,t2=0,t3=0,t4=0;
void onside(char x,char y)
{
	if( (int(x)<=67&&int(y)<=67) ||int(x)>67&&int(y)>67)
	{
		t3=1;
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return;
}
void nearside(char m,char n)
{
	if((abs( int(m)-int(n) )==1&&int(m)<=67&&int(n)<=67) || (m=='D'||n=='D') &&(m=='F'||n=='F')    )
	cout<<"1";
	else
	{
		cout<<"0";
	 } 
	 return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	sp1=(s1[0]*10+s1[1])-'0';
	sp2=(s2[0]*10+s2[1])-'0';
	ss1=s1[2];
	ss2=s2[2];
	if(c1==c2) 
	{
		t1=1;
		cout<<t1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	if(t1)
	{
		if(sp1==sp2)
		{
			cout<<"1";
			t2=1;
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	if(t2)
	onside(ss1,ss2);
	else {
		cout<<"00";
		return 0;
	}
	if(t3)
	nearside(ss1,ss2);
	else cout<<"0";
	return 0;
 } 
