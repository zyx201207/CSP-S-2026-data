#include<bits/stdc++.h>
using namespace std;
int a,c;
char b[5],d[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		int rp=(b[0]-'0')*10+(b[1]-'0'),
		xp=(d[0]-'0')*10+(d[1]-'0');
		if(rp==xp)
		{
			cout<<1;
			rp=b[2]-'A',xp=d[2]-'A';
			if((rp<=2&&xp<=2)||(rp>2&&xp>2))
			{
				cout<<1;
				if(abs(rp-xp)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
