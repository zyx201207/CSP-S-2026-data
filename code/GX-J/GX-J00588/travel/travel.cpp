#include <iostream>
#include <string>
using namespace std;
int a,b,seat1,seat2;
string c,d;
char seat_n1,seat_n2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	seat1 = (c[0] - '0')*10 + c[1] - '0';
	seat2 = (d[0] - '0')*10 + d[1] - '0';
	seat_n1 = c[2];
	seat_n2 = d[2];
	if(a == b)
	{
		cout<<"1";
		if(seat1 == seat2)
		{
			cout<<"1";
			if(seat_n1-'A'<=2 && seat_n2-'A'<=2)
			{
				cout<<"1";
				if(abs(seat_n1-seat_n2) == 1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if(seat_n1-'A'>2 && seat_n2-'A'>2)
			{
				cout<<"1";
				if(abs(seat_n1-seat_n2) == 1)
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
