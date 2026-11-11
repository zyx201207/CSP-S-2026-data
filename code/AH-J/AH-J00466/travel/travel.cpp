//travel
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	
	//
	if(a==c)//同车 
	{
		cout<<1;
		if(b[1]==d[1])//同排 
		{
			cout<<1;
			if((b[2]=='A'||b[2]=='C'||b[2]=='B')//同侧 
			&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
			{
				cout<<1;
				if(b[2]+1==d[2])
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if((b[2]=='D'||b[2]=='E')
			&&(d[2]=='E'||d[2]=='E'))
			{
				cout<<1;
				if(b[2]+1==d[2])
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
	 	} 
		else
		{
			cout<<"000";
		}
		
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}

