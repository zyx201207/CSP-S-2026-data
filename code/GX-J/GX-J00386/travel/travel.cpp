#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==c)
	{
		cout<<"1";
		if (b[0]==d[0] && b[1]==d[1])
		{
			cout<<"1";
			if ((b[3]<='F' && b[3]>='D')||(d[3]<='F' && d[3]>='D'))
			{
				cout<<"11";
			}
			else if ((b[3]<='C' && b[3]>='A')||(d[3]<='C' && d[3]>='A'))
			{
				cout<<1;
				if ((b[3]=='A' && d[3]=='C')||(b[3]=='C' && d[3]=='A'))
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
				}
			}
			else {
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
