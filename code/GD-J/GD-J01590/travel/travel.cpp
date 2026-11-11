#include <bits/stdc++.h>
using namespace std;
string c[2];
string s[2];
int main()
{
	for(int i=1;i<=2;i++)
	{
		cin>>c[i]>>s[i];
	}
	for(int i=1;i<=4;i++)
	{
		if(c[1]!=c[2])
		{
			cout<<0000;
			break;
		}
		else if(c[1]==c[2]&&s[1]==s[2])
		{
			cout<<1000;
			break;
		}
		else if(c[1]==c[2]&&s[1]!=s[2])
		{
			cout<<1100;
			break;
		}
		else
		{
			cout<<1111;
			break;
		}
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}
