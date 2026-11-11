#include<bits/stdc++.h>
using namespace std;
string cx1,cx2;
string zw1,zw2;
int main(void)
{
	//travel
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2)
	{
		//cout<<2;
		cout<<1;
		if(zw1[0]==zw2[0] && zw1[1]==zw2[1])
		{
			//cout<<2;
			cout<<1;
			char c1=zw1[2];
			char c2=zw2[2];
			//c1==D/F
			if(c1=='D' || c1=='F')
			{
				if(c2=='D' || c2=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			//c1==A/B/C
			else
			{
				if(c2=='D' || c2=='F')
				{
					cout<<"00";
				}
				else if(c1=='B')
				{
					cout<<"11";
				}
				else if(c1=='A')
				{
					if(c2=='B')cout<<"11";
					else cout<<"10";
				}
				else if(c1=='C')
				{
					if(c2=='B')cout<<"11";
					else cout<<"10";
				}
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
