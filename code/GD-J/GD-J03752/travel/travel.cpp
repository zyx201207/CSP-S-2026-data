#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,d,e;
	char c,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==d)
	{
		cout<<"1";
		if(b==e)
		{
			cout<<"1";
			if((c>'C' && f>'C') || (c<='C' && f<='C'))
			{
				cout<<"1";
				if(c-f==1 || f-c==1)
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
	return 0;
}
