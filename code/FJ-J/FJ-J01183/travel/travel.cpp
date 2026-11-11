#include <bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>rc>>rs>>xc>>xs;
	if (rc==xc){
		cout<<1;
		string tr,tx;
		tr=rs[0]+rs[1];
		tx=xs[0]+xs[1];
		if (tr==tx){
			cout<<1;
			char ttr,ttx;
			ttr=rs[2];
			ttx=xs[2];
			if (ttr=='A'&&ttx=='B') cout<<"11\n";
			else if (ttr=='A'&&ttx=='C') cout<<"10\n";
			else if (ttr=='A'&&ttx=='D') cout<<"00\n";
			else if (ttr=='A'&&ttx=='F') cout<<"00\n";
			else if (ttr=='B'&&ttx=='A') cout<<"11\n";
			else if (ttr=='B'&&ttx=='C') cout<<"11\n";
			else if (ttr=='B'&&ttx=='D') cout<<"00\n";
			else if (ttr=='B'&&ttx=='F') cout<<"00\n";
			else if (ttr=='C'&&ttx=='A') cout<<"10\n";
			else if (ttr=='C'&&ttx=='B') cout<<"11\n";
			else if (ttr=='C'&&ttx=='D') cout<<"00\n";
			else if (ttr=='C'&&ttx=='F') cout<<"00\n";
			else if (ttr=='D'&&ttx=='A') cout<<"00\n";
			else if (ttr=='D'&&ttx=='B') cout<<"00\n";
			else if (ttr=='D'&&ttx=='C') cout<<"00\n";
			else if (ttr=='D'&&ttx=='F') cout<<"11\n";
			else if (ttr=='F'&&ttx=='A') cout<<"00\n";
			else if (ttr=='F'&&ttx=='B') cout<<"00\n";
			else if (ttr=='F'&&ttx=='C') cout<<"00\n";
			else if (ttr=='F'&&ttx=='D') cout<<"11\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}
