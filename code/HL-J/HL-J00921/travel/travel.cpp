#include <bits/stdc++.h>

using namespace std;
bool fl = 1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		printf("%d",1);
	}
	else
	{
		printf("%d",0);
		fl = 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&fl)
	{
		printf("%d",1);
	}
	else
	{
		printf("%d",0);
		fl = 0;
	}
	if(a2[2]<='C'&&b2[2]<='C'&&fl||a2[2]>'C'&&b2[2]>'C'&&fl)
	{
		printf("%d",1);
	}
	else
	{
		printf("%d",0);
		fl = 0;
	}
	if(abs(a2[2]-b2[2])==1&&fl)
	{
		printf("%d",1);
	}
	else
	{
		printf("%d",0);
	}
	return 0;
}