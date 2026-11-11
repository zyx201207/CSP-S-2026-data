#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int f = b[2]-'A';
	int j = d[2]-'A';
	if(a==c)
	{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<1;
			if((f<=2&&j<=2)||(f>2&&j>2))
			{
				cout<<1;
				if(f-j==1||j-f==1)
				{
					cout<<1;
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
