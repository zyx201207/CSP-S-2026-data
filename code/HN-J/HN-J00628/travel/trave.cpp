#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	char x[5],y[5],a[5],s[5];
	cin>>x>>y>>a>>s;
	if(x==a)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(x==a&&y[1]==s[1]&&y[2]==s[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(y[3]=='A'||y[3]=='B'||y[3]=='C'&&s[3]=='A'||s[3]=='B'||s[3]=='C')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((y[3]=='A'&&s[3]=='B')||(y[3]=='B'&&s[3]=='C')||(y[3]=='F'&&s[3]=='D')||(y[3]=='B'&&s[3]=='A')||(y[3]=='D'&&s[3]=='F')||(y[3]=='C'&&s[3]=='B'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
	
}
