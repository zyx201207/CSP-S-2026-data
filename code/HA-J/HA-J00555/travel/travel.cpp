#include<bits/stdc++.h>
using namespace std;
string q,w,e,r;
int main()
{
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	cin>>q>>w>>e>>r;
	
	if(q==e)
	{
		if(w[0]==r[0]&&w[1]==r[1])
		{
			if((w[2]=='A'&&r[2]=='B')||(w[2]=='A'&&r[2]=='C')||(w[2]=='B'&&r[2]=='C')||(w[2]=='B'&&r[2]=='A')||(w[2]=='C'&&r[2]=='A')||(w[2]=='C'&&r[2]=='B')||(w[2]=='D'&&r[2]=='F')||(w[2]=='E'&&r[2]=='F'))
			{
				if((w[2]=='A'&&r[2]=='B')||(w[2]=='B'&&r[2]=='C')||(w[2]=='B'&&r[2]=='A')||(w[2]=='C'&&r[2]=='B')||(w[2]=='D'&&r[2]=='F')||(w[2]=='F'&&r[2]=='D'))
				{
					cout<<"1111"<<endl;
					return 0;
				}
				else
				{
					cout<<"1110"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<"1100"<<endl;
				return 0;
			}
		}
		else
		{
			cout<<"1000"<<endl;
		}
	}
	else
	{
		cout<<"0000"<<endl;
	}
	return 0;
}
