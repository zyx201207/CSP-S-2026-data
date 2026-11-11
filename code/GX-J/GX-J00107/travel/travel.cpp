#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string Rc,Rs,Xc,Xs;
	
	cin>>Rc>>Rs>>Xc>>Xs;
	if(Rc==Xc) cout<<1;
	else {cout<<0<<0<<0<<0;return 0;}
	
	if(Rs[0]==Xs[0]&&Rs[1]==Xs[1]) cout<<1;
	else {cout<<0<<0<<0;return 0;}
	
	if(((Rs[2]=='A'||Rs[2]=='B'||Rs[2]=='C')&&(Xs[2]=='A'||Xs[2]=='B'||Xs[2]=='C'))||((Rs[2]=='D'||Rs[2]=='F')&&(Xs[2]=='D'||Xs[2]=='F'))) cout<<1;
	else {cout<<0<<0;return 0;}
	
	if((Rs[2]=='A'&&Xs[2]=='B')||(Rs[2]=='B'&&Xs[2]=='A')||(Rs[2]=='C'&&Xs[2]=='B')||(Rs[2]=='B'&&Xs[2]=='C')||(Rs[2]=='D'&&Xs[2]=='F')||(Rs[2]=='F'&&Xs[2]=='D')) cout<<1;
	else {cout<<0;return 0;}
	return 0;
}
