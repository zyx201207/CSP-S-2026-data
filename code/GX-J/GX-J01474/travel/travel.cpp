#include<bits/stdc++.h>
using namespace std;
long long a,c;
string b,d,e,f;
char g,h;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	g=b[2];
	h=d[2];
	if(g>h)
	{
		swap(g,h);
	}
	if(a!=c)
	{
		cout<<"0000";
	}
	else if(!(b[0]==d[0]&&b[1]==d[1]))
	{
		cout<<"1000";
	}
	else
	{
		if((g=='A'&&h=='B')||(g=='B'&&h=='C')||(g=='D'&&h=='E'))
		{
			cout<<"1111";
		}
		else if(g=='A'&&h=='C')
		{
			cout<<"1110";
		}
		else
		{
			cout<<"1100";
		}
	}
	return 0;
}
