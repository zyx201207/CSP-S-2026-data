#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a1,a2,a3,a4;
char b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a1>>a2>>b1>>a3>>a4>>b2;
	if(a1==a3)
	{
		if(a2==a4)
		{
			if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='A')||(b1=='B'&&b2=='C')||(b1=='C'&&b2=='B')||(b1=='D'&&b2=='F')||(b1=='F'&&b2=='D')||(b1=='A'&&b2=='C')||(b1=='C'&&b2=='A'))
			{
				if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='A')||(b1=='B'&&b2=='C')||(b1=='C'&&b2=='B')||(b1=='D'&&b2=='F')||(b1=='F'&&b2=='D'))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
//100+60+45+20=225(1h)
//100+60+75+24=259(1.5h)
//100+60+85+28=273(2h)
//100+60+[75,100]+28=[263,288](2.2h)
//没有进展了,u1381480
