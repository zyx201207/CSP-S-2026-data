#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ak=0,bs=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	ak=int(b[2]);
	bs=int(d[2]);
	if(a==c)
	{
		cout<<"1";
		if(b[0]==d[0] && b[1]==d[1])
		{
			cout<<"1";
			if((ak<=67 && bs<=67)||(ak>67 && bs>67))
			{
				cout<<"1";
				if(ak-bs==1 || bs-ak==1)cout<<"1";
				else
					cout<<"0"; 
			}
			else 
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
