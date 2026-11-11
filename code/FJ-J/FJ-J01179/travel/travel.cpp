#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool z=false;
	if (a==c)
	{
		cout<<1;
		z=true;
	}
	else cout<<0;
	for (int i=1;i<=3;i++)
	{
		if (!z)
		{
			cout<<0;
		}
		else if (i==1 && (b[0]==d[0] && b[1]==d[1]))
		{
			cout<<1;
		}
		else if (i==2 && ((b[2]<'C' && d[2]<'C') || (b[2]>'C' && d[2]>'C')))
		{
			cout<<0;
		}
		else if (i==3 &&(b[2]-d[2]==1 || b[2]-d[2]==-1))
		{
			cout<<1;
		}
		else 
		{
			z=false;
			cout<<0;
		}
	}
} 
