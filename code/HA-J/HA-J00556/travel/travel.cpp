#include<bits/stdc++.h>
using namespace std;
#define LL long long
int r,x;
string rr,xx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rr>>x>>xx;
	int rt=(rr[0]-'0')*10+rr[1]-'0';
	int xt=(xx[0]-'0')*10+xx[1]-'0';
	if(r==x)
	{
		cout<<1;
		if(rt==xt)
		{
			cout<<1;
			if((rr[2]>='D'&&xx[2]>='D')||(rr[2]<'D'&&xx[2]<'D'))
			{
				cout<<1;
				if(rr[2]+1==xx[2]||xx[2]+1==rr[2])cout<<1;
				else if(rr[2]=='D'||xx[2]=='D')cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
