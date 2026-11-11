#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string rr,xx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>rr>>x1>>xx;
	if(r1==x1) cout<<"1";
	else cout<<"0";
	if(rr.substr(0,2)==xx.substr(0,2) && r1==x1) cout<<"1";
	else cout<<"0";
	if(rr.substr(0,2)==xx.substr(0,2) && r1==x1 && !((rr[2]=='C' && xx[2]=='D') || (rr[2]=='D' && xx[2]=='C')))
	{
		cout<<"1";
	}
	else cout<<"0";
	if(rr.substr(0,2)==xx.substr(0,2) && r1==x1 && !((rr[2]=='C' && xx[2]=='D') || (rr[2]=='D' && xx[2]=='C')) && abs(rr[2]-xx[2])==1)
	{
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
