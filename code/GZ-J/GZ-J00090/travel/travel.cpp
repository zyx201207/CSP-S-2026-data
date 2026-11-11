//GZ-J00090 ºÎÓêĞù 
#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cr[1]==cx[1])
	{
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1])
		{
			cout<<1;
			if((sr[2]<='C'&&sx[2]<='C')||(sr[2]>='D'&&sx[2]>='D'))
			{
				cout<<1;
				if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D'))
				{
					cout<<1;
				}
				else
				{
					cout<<0; 
				}
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
		
	}
	return 0;
}
