#include<bits/stdc++.h>
using namespace std;
int che1,che2,zuo1,zuo2;
char zu1,zu2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>che1>>zuo1>>zu1>>che2>>zuo2>>zu2;
	if(che1==che2)
	{
		cout<<1;
		if(zuo1==zuo2)
		{
			cout<<1;
			if((zu1<='C'&&zu2<='C')||(zu1>='D'&&zu2>='D'))
			{
				cout<<1;
				int x,y;
				x=(int)zu1;
				y=(int)zu2;
				if(abs(x-y)==1)
				{
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	
	
	
	
	return 0;
}
