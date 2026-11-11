#include<bits/stdc++.h>
#include "travel.h"
using namespace std;
int a,b;
char s[]={'0','0','0','0','0','0','0','0'};
string c,d;
bool f1,f2,f3;
int main()
{
NewFunction();
	cin >> a >> c >> b>> d;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	if(a==b)
	{
		s[1]='1';
		f1=1;
	}
	if(f1&&c[0]==d[0]&&c[1]==d[1])
	{
		s[2]='1';
		f2=1;
	}
	if(f2&&(((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F'))))
	{
		s[3]='1';
		f3=1;
	}
	if(f3&&(((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')||(c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B'))||((c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D'))))
	{
		s[4]='1';
	}
	cout<<s[1]<<s[2]<<s[3]<<s[4];
	return 0;
}

void NewFunction()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",(__acrt_iob_func(1)));
}
