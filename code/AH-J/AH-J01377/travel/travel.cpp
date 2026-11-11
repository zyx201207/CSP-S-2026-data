#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==c) cout<<1;
	else {cout<<"0000"; return 0;}
	if (b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else {cout<<"000"; return 0;}
	int l1,l2;
	if (b[2]=='D'||b[2]=='F') l1=1;
	else l1=0;
	if (d[2]=='D'||d[2]=='F') l2=1;
	else l2=0;
	if (l1==l2) cout<<1;
	else {cout<<"00"; return 0;}
	if (d[2]=='D'&&b[2]=='F') cout<<1;
	else if (d[2]=='F'&&b[2]=='D') cout<<1;
	else if (d[2]=='B'&&b[2]=='C') cout<<1;
	else if (d[2]=='B'&&b[2]=='A') cout<<1;
	else if (d[2]=='C'&&b[2]=='B') cout<<1;
	else if (d[2]=='A'&&b[2]=='B') cout<<1;
	else cout<<0;
	return 0;
}
