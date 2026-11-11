#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int a=0,b=0,d=0,e=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if (c==c1)
	{
		a=1;
		if (s[0]==s1[0] && s[1]==s1[1] && ((s[2]<='C' && s1[2]<='C') || (s[2]>='D' && s1[2]>='D')))
		{
			b=1;
			d=1;
			if (s[2]-1==s1[2] || s1[2]-1==s[2])
			{
				e=1;
			}
		}
		else if (s[0]==s1[0] && s[1]==s1[1] && !((s[2]<='C' && s1[2]<='C') || (s[2]>='D' && s1[2]>='D')))
		{
			b=1;
		}
	}
	cout<<a<<b<<d<<e;
	return 0;
 } 
