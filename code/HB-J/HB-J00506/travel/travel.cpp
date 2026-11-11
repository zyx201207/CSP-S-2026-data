#include<bits/stdc++.h>
using namespace std;
string a,r,b,x;
int main(void)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>r>>b>>x;
    if(a==b)
    {
		cout<<"1";
		for(int i=0;i<2;i++)
		{
			if(r[i]!=x[i])
			{
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		if(r[2]=='A'||r[2]=='B'||r[2]=='C')
		{
			if(x[2]=='A'||x[2]=='B'||x[2]=='C')
			{
				cout<<"1";
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else if(r[2]=='D'||r[2]=='F')
		{
			if(x[2]=='D'||x[2]=='F')
			{
				cout<<'1';
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		if(r[2]=='A'&&x[2]=='B')
		{
			cout<<"1";
		}
		else if(r[2]=='B'&&x[2]=='A')
		{
			cout<<"1";
		}
		else if(r[2]=='B'&&x[2]=='C')
		{
			cout<<"1";
		}
		else if(r[2]=='C'&&x[2]=='B')
		{
			cout<<"1";
		}
		else if(r[2]=='F'&&x[2]=='D')
		{
			cout<<"1";
		}
		else if(r[2]=='D'&&x[2]=='F')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
