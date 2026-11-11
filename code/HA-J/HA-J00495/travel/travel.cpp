#include<bits/stdc++.h>
using namespace std;
struct e{
	string a,b;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	e a,b;
	cin>>a.a>>a.b>>b.a>>b.b;
	if(a.a==b.a)
	{
		cout<<1;
		if(a.b[0]+a.b[1]==b.b[0]+b.b[1])
		{
			cout<<1;
			if(a.b[2]=='A'||a.b[2]=='B'||a.b[2]=='C'){
				if(b.b[2]=='A'||b.b[2]=='B'||b.b[2]=='C')
				{
					cout<<1;
					if(a.b[2]=='A'&&b.b[2]=='B')
					{
						cout<<1;
					}
					else if((a.b[2]=='B'&&b.b[2]=='A')||(a.b[2]=='B'&&b.b[2]=='C'))
					{
						cout<<1;
					}
					else if(a.b[2]=='C'&&b.b[2]=='B')
					{
						cout<<1;
					}
				    else
					{
				    	cout<<"0";
				    }
				}
				else{
					cout<<"00";
				}
			}
			else if(a.b[2]=='D'||a.b[2]=='F')
			{
				if(b.b[2]=='D'||b.b[2]=='F')
				{
					cout<<11;
				}
				else
				{
					cout<<"00";
				}
			}
			else{
			
				cout<<"000";
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
