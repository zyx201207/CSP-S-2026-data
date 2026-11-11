#include <bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;
string s[4];
int a,b,c,d;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		b=1;
	}
	if(b==1&&((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'D'>=0&&s2[2]-'D'>=0)))
	{
		c=1;
	}
	if(c==1)
	{
		if(s1[2]<='C'&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1))
		{
			d=1;
		}
		else if(s1[2]=='D'||s1[2]=='F')
		{
			d=1;
		}
	}
	cout<<a<<b<<c<<d<<endl;
	return 0;
}
