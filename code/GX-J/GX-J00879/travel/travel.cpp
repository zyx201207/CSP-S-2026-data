#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	int z,zz;
	bool aflag=0,bflag=0,cflag=0;
	string w,ww;
    cin>>z;
    cin>>w;
    cin>>zz;
    cin>>ww;
    //1
    if(z!=zz) cout<<'0';
	else {cout<<'1'; aflag=1; }
	//2
	if(aflag==1){
	if(w[0] != ww[0] and w[1] != ww[1]) cout<<'0';
	else if(w[0] == ww[0] and w[1] != ww[1]) cout<<'0';
	else if(w[0] != ww[0] and w[1] == ww[1]) cout<<'0';
	else {cout<<'1'; bflag=1; }
	}
	else if(aflag == 0) cout<<'0';
	//3
	if(bflag==1){
			if(w[2]+ww[2] == 132) {cout<<'1'; cflag=1;}
            else if(w[2]+ww[2] == 135) {cout<<'0'; cflag=0;}
			else if(w[2]+ww[2] == 131) {cout<<'1'; cflag=1;}
			else if(w[2]+ww[2] == 137) {cout<<'1'; cflag=1;}
			else if(w[2]=='C' and ww[2] =='B') {cout<<'1'; cflag=1;}
			else if(w[2]=='B' and ww[2] =='C') {cout<<'1'; cflag=1;}
			else cout<<'0';
	}
	else if(bflag == 0) cout<<'0';
	//4
	if(aflag == 1 and cflag == 1){
	if(ww[2]+1 == w[2] or ww[2]-1 == w[2]) cout<<'1';
	else cout<<'0';
	}
	else if(aflag == 0 or bflag == 0 or cflag==0) cout<<"0";


	return 0;
}
