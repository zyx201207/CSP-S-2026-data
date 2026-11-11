#include<bits/stdc++.h>
using namespace std;
string rc,rp,xc,xp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rp>>xc>>xp;
	bool a=(rc==xc);
	bool b=(rp[0]==xp[0]&&rp[1]==xp[1]);
	bool c=((rp[2]=='A'&&xp[2]=='B')||(rp[2]=='A'&&xp[2]=='C')||(rp[2]=='B'&&xp[2]=='C')||(rp[2]=='D'&&xp[2]=='F')||(rp[2]=='B'&&xp[2]=='A')||(rp[2]=='C'&&xp[2]=='A')||(rp[2]=='C'&&xp[2]=='B')||(rp[2]=='F'&&xp[2]=='D'));
	bool d=((rp[2]=='A'&&xp[2]=='B')||(rp[2]=='B'&&xp[2]=='C')||(rp[2]=='F'&&xp[2]=='D')||(rp[2]=='D'&&xp[2]=='F')||(rp[2]=='B'&&xp[2]=='A')||(rp[2]=='C'&&xp[2]=='B'));
	if(a)cout<<1;
	else cout<<0;
	if(a&&b)cout<<1;
	else cout<<0;
	if(a&&b&&c)cout<<1;
	else cout<<0;
	if(a&&b&&c&&d)cout<<1;
	else cout<<0; 
	return 0;
} 
