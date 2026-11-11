#include<bits/stdc++.h>
using namespace std;
string n1,n2,n3,n4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>n2>>n3>>n4;
	if(n1==n3)
	{
		if(n2[0]==n4[0]&&n2[1]==n4[1])
		{
			if(n2[2]<='C'&&n4[2]<='C'||n2[2]>'C'&&n4[2]>'C')
			{
				if(n2[2]-n4[2]==1||n2[2]-n4[2]==-1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else cout<<"0000";
	return 0;
}
