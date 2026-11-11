#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sr[1]==sx[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(sr[2]=='A'&&sx[2]!='D'&&sx[2]!='F'){
		cout<<"1";
	}
	else if(sr[2]=='B'&&sx[2]!='D'&&sx[2]!='F'){
		cout<<"1";
	}
	else if(sr[2]=='C'&&sx[2]!='D'&&sx[2]!='F'){
		cout<<"1";
	}
	else if(sr[2]=='D'&&sx[2]=='F'){
		cout<<"11";
		return 0;
	}
	else if(sr[2]=='F'&&sx[2]=='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(sr[2]+1==sx[2]||sr[2]-1==sx[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
