#include<bits/stdc++.h>
using namespace std;
long long c1,c3;
string c2,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(!(c1==c3))
	{
		cout<<"0000";
	}
	else 
	{
		cout<<1;
		if(!(c2[0]==c4[0]&&c2[1]==c4[1]))
		{
			cout<<"000";
		}
		else 
		{
			cout<<1;
			if(!(c2[2]>'C'&&c4[2]>'C'||c2[2]<='C'&&c4[2]<='C'))
			{
				cout<<"00";
			}
			else
			{
				cout<<1;
				if(abs(c2[2]-c4[2])==1)
				{
					cout<<1;	
				}	
				else cout<<0;
			}		
		}		
	}
	return 0;
}

