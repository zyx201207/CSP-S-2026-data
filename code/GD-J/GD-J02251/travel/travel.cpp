#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	x=b[0]+b[1];
	y=d[0]+d[1];
	if(a==c)
	{
		if(x==y)
		{
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))
			{
				if(abs(b[2]-d[2])==1)
				{
					cout<<"1111";
				}
				else
					cout<<"1110";
			}
			else
				cout<<"1100";
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
		
	return 0;
 } 
