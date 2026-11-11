
#include <iostream>
using namespace std;
bool check(string x,string y)
{
	if(x[2]<='C'&&y[2]>'C')
	{
		return false;
	}
	if(y[2]<='C'&&x[2]>'C')
	{
		return false;
	}
	return true;
}
bool checkin(string m,string n)
{
    if((m[2]=='A'&&n[2]=='C')||(n[2]=='A'&&m[2]=='C'))
	{
		return false;
	}
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	if(ax==bx)
	{
		cout<<1;
		if((ay[0]-'0')+(ay[1]-'0')==(by[0]-'0')+(by[1]-'0'))
		{
			cout<<"1";
			if(check(ay,by))
			{
				cout<<"1";
				if(checkin(ay,by))
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
