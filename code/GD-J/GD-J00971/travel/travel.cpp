#include<bits/stdc++.h>
using namespace std;
string rc, rs, xc, xs;
int rsint, xsint, rseat, xseat;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc == xc){
		cout<<"1";
		if((rs[0]==xs[0]) && (rs[1]==xs[1])){
			cout<<"1";
			if(rs[2]=='A' || rs[2]=='B' || rs[2]=='C') rsint=1;
			else rsint=2;
			if(xs[2]=='A' || xs[2]=='B' || xs[2]=='C') xsint=1;
			else xsint=2;
			if(rsint == xsint){
				cout<<"1";
				rseat=rs[2]-'A';
				xseat=xs[2]-'A';
				if(xseat+1==rseat || xseat-1==rseat || (rs[2]=='D' && xs[2]=='F') || (rs[2]=='F' && xs[2]=='D')){
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
} 
