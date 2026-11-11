#include <bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>n>>m;
	if(a==n)
	{
		cout<<"1";
		int o=int(b[0]-'0')*10+int(b[1]-'0'),c=int(m[0]-'0')*10+int(m[1]-'0');
		if(o==c)
		{
			cout<<"1";
			if((a[2]<='C'&&m[2]<='C')||(a[2]>'C'&&m[2]>'C'))
			{
				cout<<"1";
				int f=abs(b[2]-m[2]);
				if(f==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
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
}
