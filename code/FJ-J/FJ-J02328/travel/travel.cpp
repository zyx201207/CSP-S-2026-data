#include<bits/stdc++.h>
using namespace std;
char sr[3],sx[3];
int cr,cx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<1;
			int f=1;
			if((sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D')) cout<<1;
			else if((sr[2]=='C'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')) cout<<1;
			else if((sr[2]=='C'&&sx[2]=='A')||(sr[2]=='A'&&sx[2]=='C')){
				cout<<1;
				f=0;
			}
			else if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')) cout<<1;
			else {
				cout<<0;
				f=0;
			}
			if(f==1) cout<<1;
			else cout<<0;
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
