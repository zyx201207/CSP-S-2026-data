#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int r1,x1,r2,x2;char r3,x3;cin>>r1>>r2>>r3>>x1>>x2>>x3;
	if(r1==x1)
	{
		cout<<1;
		if(r2==x2)
		{
			cout<<1;
			if((r3>='A'&&r3<='C'&&x3>='A'&&x3<='C')||(r3>='D'&&r3<='F'&&x3>='D'&&x3<='F'))
			{
				cout<<1;
				if(abs(r3-x3)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
