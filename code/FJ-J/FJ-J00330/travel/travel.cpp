#include <bits/stdc++.h>
using namespace std;
string as,ac,bs,bc,ans;
bool check (){
	char a=ac[2],b=bc[2];
	if ((a=='F'&&b=='D')||(a=='D'&&b=='F')) return 1;
	else if ((a=='C'&&b=='B')||(a=='B'&&b=='C')) return 1;
	else if ((a=='B'&&b=='A')||(a=='A'&&b=='B')) return 1;
	else return 0;
}

int main (){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>as>>ac>>bs>>bc;
	if (as==bs){
		cout<<1;
		if (ac[0]==bc[0]&&ac[1]==bc[1]){
			cout<<1;
			
			bool a=0,b=0;
			if (ac[2]=='D'||ac[2]=='F') a=1;
			if (bc[2]=='D'||bc[2]=='F') b=1;
			if (b==a){
				cout<<1;
				if (check()){
					cout<<1;
				}
				else {
					cout<<"0";
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	
	return 0;
}
