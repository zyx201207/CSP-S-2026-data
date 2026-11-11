#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string e=b.substr(0,2),f=d.substr(0,2);
	int g,h;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(e==f)
	{
		cout<<1;
		g=b[2]-'A'+1,h=d[2]-'A'+1;
		if(((g!=3||h!=4)&&(h!=3||g!=4))&&abs(g-h)==1)
		{
			cout<<11;
		}
		else
		{
			if(((g!=3||h!=4)&&(h!=3||g!=4))&&((g==1&&h==3)||(g==3&&h==1)))
			{
				cout<<10;
			}
			else
			{
				cout<<0<<0;
			}
		}
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	return 0;
}
