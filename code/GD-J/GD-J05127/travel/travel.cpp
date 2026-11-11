#include<bits/stdc++.h>
using namespace std;
long long a1,a2,b1,b2;
string s1,s2;
char ch1,ch2;
bool pd(char c,char b)
{
	if((b=='F'&&c=='D')||(b=='D'&&c=='F'))
		return true;
	if(c=='A'&&(b=='C'||b=='B'))
		return true;
	if(c=='B'&&(b=='C'||b=='A'))
		return true;
	if(c=='C'&&(b=='A'||b=='B'))
		return true;
	return false;
}
bool pd1(char c,char b)
{
	if(c=='B'&&(b=='C'||b=='A'))
		return true;
	if(b=='B'&&(c=='C'||c=='A'))
		return true;
	if((b=='F'&&c=='D')||(b=='D'&&c=='F'))
		return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%s%lld%s",a1,s1,a2,s2);
	ch1=s1[2];
	ch2=s2[2];
	b1=(s1[0]-'0')*10+s1[1]-'0';
	b2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1!=a2)
		cout<<"0000";
	else
	{
		cout<<1;
		if(b1!=b2)
			cout<<"000";
		else
		{
			cout<<1;
			if(!pd(ch1,ch2))
				cout<<"00";
			else
			{
				cout<<1;
				if(!pd1(ch1,ch2))
					cout<<0;
				else
					cout<<1;
			}
		}
	}
	return 0;
}
