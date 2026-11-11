#include<bits/stdc++.h>
using namespace std;
string n,m,l,p;
bool a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>l>>p;
	if(m[2]=='F')
	{
		m[2]='E';
	}
	if(p[2]=='F')
	{
		p[2]='E';
	}
	if(n==l)
	{
		if(m[0]==p[0]&&m[1]==p[1])
		{
			int temp=0,tmp=0;
			if(m[2]-'A'<3)
			{
				temp=1;
			}
			if(p[2]-'A'<3)
			{
				tmp=1;
			}
			if(!temp^tmp)
			{
				if(abs(m[2]-p[2])<=1)
				{
					cout<<1111;return 0;
				}
				else
				{
					cout<<1110;return 0;
				}
			}
			else
			{
				cout<<1100;return 0;
			}
		}
		else
		{
			cout<<1000;return 0;
		}
	}
	else
	{
		cout<<"0000";return 0;
	}
	return 0;
}
