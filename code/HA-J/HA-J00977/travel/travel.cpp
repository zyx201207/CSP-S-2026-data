#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string caa,cbb,ccc,cdd;//a，b为小R车厢，座位。c，d为小X的 
	cin>>caa>>cbb>>ccc>>cdd;
	if(caa==ccc)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(caa==ccc&&cbb[0]==cdd[0]&&cbb[1]==cdd[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(caa==ccc&&cbb[0]==cdd[0]&&cbb[1]==cdd[1]&&((cbb[2]=='A'&&cdd[2]=='B')||(cbb[2]=='A'&&cdd[2]=='C')||(cbb[2]=='B'&&cdd[2]=='A')||(cbb[2]=='B'&&cdd[2]=='C')||(cbb[2]=='C'&&cdd[2]=='A')||(cbb[2]=='A'&&cdd[2]=='B')||(cbb[2]=='D'&&cdd[2]=='F')||(cbb[2]=='F'&&cdd[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(caa==ccc&&cbb[0]==cdd[0]&&cbb[1]==cdd[1]&&((cbb[2]=='A'&&cdd[2]=='B')||(cbb[2]=='B'&&cdd[2]=='A')||(cbb[2]=='B'&&cdd[2]=='C')||(cbb[2]=='A'&&cdd[2]=='B')||(cbb[2]=='D'&&cdd[2]=='F')||(cbb[2]=='F'&&cdd[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
