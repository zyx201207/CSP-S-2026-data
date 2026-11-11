#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string b,c,d,e;
    int i;
    cin>>b>>c>>d>>e;
    for(i=0;i<2;i++)
    {
		if(b[i]!=d[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	for(i=0;i<2;i++)
    {
		if(c[i]!=e[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	if((c[2]=='A'&&e[2]=='B')||
	(c[2]=='B'&&e[2]=='A')||(c[2]=='B'&&e[2]=='C')||
	(c[2]=='C'&&e[2]=='B')||
	(c[2]=='D'&&e[2]=='F')||
	(c[2]=='F'&&e[2]=='D'))
	{
		cout<<"1111";
	}
	else if((c[2]=='C'&&e[2]=='D')||(c[2]=='C'&&e[2]=='F'))
	{
		cout<<"1100";
	}
	else if((c[2]=='A'&&e[2]=='D')||(c[2]=='A'&&e[2]=='F'))
	{
		cout<<"1100";
	}
	else if((c[2]=='B'&&e[2]=='D')||(c[2]=='B'&&e[2]=='F'))
	{
		cout<<"1100";
	}
	else if((c[2]=='D'&&e[2]=='A')||(c[2]=='D'&&e[2]=='B')||(c[2]=='D'&&e[2]=='C'))
	{
		cout<<"1100";
	}
	else if((c[2]=='F'&&e[2]=='A')||(c[2]=='F'&&e[2]=='B')||(c[2]=='F'&&e[2]=='C'))
	{
		cout<<"1100";
	}
	else cout<<"1110";
    return 0;
}
