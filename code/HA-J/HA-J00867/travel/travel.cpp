#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c)
	{
		cout<<"1";
		char aa=b[0]+b[1];
		char bb=d[0]+d[1];
		if(aa==bb)
		{
			cout<<"1";
			char a1=b[2];
			char b1=d[2];
			if((a1=='F' && b1=='D') || (a1=='D' && b1=='F') || (a1=='A' && b1=='C') || (a1=='C' && b1=='A'))
			{
				cout<<"1";
				if((!(a1=='A' && b1=='C')) && (!(a1=='C' && b1=='A')))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if((a1=='A' && b1=='B') || (a1=='B' && b1=='A') || (a1=='B' && b1=='C') || (a1=='C' && b1=='B'))
			{
				cout<<"1";
				if((!(a1=='A' && b1=='C')) && (!(a1=='C' && b1=='A')))
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
