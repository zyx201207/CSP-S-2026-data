#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1l,s2l;
char s1h,s2h;
bool f; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	scanf("%d %d%c %d %d%c",&c1,&s1l,&s1h,&c2,&s2l,&s2h);
	if(c1==c2) cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1l==s2l) cout<<'1';
	else cout<<'0';
	char a='A';
	f=0;
	if(c1==c2&&s1l==s2l)
	{
		for(int i=0;i<3;i++)
		{
			if(s1h==a+char(i)) f=1;
		}
		if(f&&(s2h=='A'||s2h=='B'||s2h=='C')) cout<<'1';
		else if(!f&&(s2h=='D'||s2h=='F')) cout<<'1';
	}
	else cout<<'0';
	if(c1==c2&&s1l==s2l)
	{
		if(s1h=='A'&&s2h=='B') cout<<'1';
		else if(s1h=='B'&&(s2h=='A'||s2h=='C')) cout<<'1';
		else if(s1h=='C'&&s2h=='B') cout<<'1';
		else if(s1h=='D'&&s2h=='F') cout<<'1';
		else if(s1h=='F'&&s2h=='D') cout<<'1';
		else cout<<'0';
	}
	else cout<<'0';
	return 0;
} 
