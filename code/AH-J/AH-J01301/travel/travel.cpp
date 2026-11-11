#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx,tr,tx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	if(cr==cx){
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<1;
			char a=sr[2],b=sx[2];
			if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||
			(a=='C'&&b=='A')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
				cout<<1;
				if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||
				(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
