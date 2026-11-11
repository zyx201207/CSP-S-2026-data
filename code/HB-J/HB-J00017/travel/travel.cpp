#include <bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main()
{
	freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c)
	{
		cout<<1;
		if (b[0]-'0'==d[0]-'0' && b[1]-'0'==d[1]-'0')
		{
			cout<<1;
			if ((b[2]-'A'<=3 && d[2]-'A'<=3) || 
			(b[2]-'A'>3 && d[2]-'A'>3))
			{
				cout<<1;
				if (b[2]-'A'-(d[2]-'A')==1 || d[2]-'A'-(b[2]-'A')==1)
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
				cout<<00;
			}
		}
		else
		{
			cout<<000;
		}
	}
	else
	{
		cout<<0000;
	}
	return 0;
}
