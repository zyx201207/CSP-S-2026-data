#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		if(b[0]==d[0] && b[1]==d[1])
		{
			cout<<"1";
			long long x=5,r=5;
			if(b[2]=='A' || b[2]=='B' || b[2]=='C')
			{
				x=0;
			}
			else
			{
				x=1;
			}
			if(d[2]=='A' || d[2]=='B' || d[2]=='C')
			{
				r=0;
			}
			else
			{
				r=1;
			}
			if(x==r)
			{
				cout<<"1";
				if(b[2]-d[2]==1 || b[2]-d[2]==-1)
				{
					cout<<"1"<<endl;
					return 0;
				}
				else
				{
					cout<<"0"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<"00"<<endl;
				return 0;
			}
		}
		else
		{
			cout<<"000"<<endl;
			return 0;
	    }
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
		
	}
	return 0;
 } 
