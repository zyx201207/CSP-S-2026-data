#include<bits/stdc++.h>
using namespace std;
int get(char x,char y)
{
	if(x>y) swap(x,y);
	if(x=='D'&&y=='F') return 1;
	return y-x;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) putchar('1');
	else putchar('0');
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) putchar('1');
	else putchar('0');
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) putchar('1');
		else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) putchar('1');
		else putchar('0');
	}
	else putchar('0');
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&get(s1[2],s2[2])==1)
	{
		if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) putchar('0');
		else putchar('1');
	}
	else putchar('0');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
