#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string s,x,st,xt;
	int s_ce,x_ce,sp,xp;
	cin>>s>>st>>x>>xt;
	if (st[2]=='A') sp=1;
	else if (st[2]=='B') sp=2;
	else if (st[2]=='C') sp=3;
	else if (st[2]=='D') sp=5;
	else if (st[2]=='F') sp=6;
	if (xt[2]=='A') xp=1;
	else if (xt[2]=='B') xp=2;
	else if (xt[2]=='C') xp=3;
	else if (xt[2]=='D') xp=5;
	else if (xt[2]=='F') xp=6;
	if (st[2]=='A' || st[2]=='B' || st[2]=='C') s_ce=1;
	else s_ce=0;
	if (xt[2]=='A' || xt[2]=='B' || xt[2]=='C') x_ce=1;
	else x_ce=0;
	if (s==x) cout<<1;
	else cout<<0;
	if (s==x && st[1]==xt[1] && st[0]==xt[0]) cout<<1;
	else cout<<0;
	if (s==x && st[1]==xt[1] && st[0]==xt[0] && s_ce==x_ce) cout<<1;
	else cout<<0;
	if (s==x && abs(sp-xp)==1 && st[0]==xt[0] && abs(st[1]-xt[1])==1) cout<<0;
	else if (s==x && abs(sp-xp)<=1 && st[0]==xt[0] && abs(st[1]-xt[1])<=1) cout<<1;
	else cout<<0;
	
}
