#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s;
long long u;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	s=s+b[0]+b[1];
	u=stoll(s);
	s="";
	s=s+d[0]+d[1];
	if(a==c)
	{
		cout<<1;
		if(stoll(s)==u)
		{
			cout<<1;
			if(b[2]=='F'||b[2]=='D')
			{
				if(d[2]=='F'||d[2]=='D')
				{
					cout<<"11";
				}
				else cout<<"00";
			}
			else
			{
				if(d[2]=='A'||d[2]=='B'||d[2]=='C')
				{
					cout<<1;
					if(d[2]=='B'||b[2]=='B')cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
//anyone florr
