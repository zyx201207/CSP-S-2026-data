#include<bits/stdc++.h>
using namespace std;
int e,f;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		if(b[0]==d[0]&&b[1]==d[1])
		{
			e=b[2]-'A';
			f=d[2]-'A';
			if(e<=2&&f<=2)
			{
				if(e-f==1||f-e==1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else if(e>=3&&f>=3)
			{
				cout<<"1111";
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
	else
	{
		cout<<"0000";
	}
	return 0;
}
