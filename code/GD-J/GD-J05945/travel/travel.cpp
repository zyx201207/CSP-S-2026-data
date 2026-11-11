#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	string o,p;
	o=c[0]+c[1];
	p=d[0]+d[1];
	int x,y;
	x=c[2]-65;
	y=d[2]-65;
	if(a==b)
	{
		cout<<"1";
		if(o==p)
		{
			cout<<"1";
			if((x<=2&&y<=2)||(x>2&&y>2))
			{
				cout<<"1";
				if(max(x,y)-min(x,y)==1)
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
