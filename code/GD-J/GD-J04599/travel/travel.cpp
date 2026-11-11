#include<bits/stdc++.h>
using namespace std;
string co,so,ct,st;
bool ff=false,fs=false,ft=false;
bool gd(char a,char b){
	if(a=='A' || a=='B' || a=='C'){
		if(b=='A' || b=='B' || b=='C'){
			return true;
		}
	}
	if(a=='D' || a=='F'){
		if(b=='D' || b=='F'){
			return true;
		}
	}
	return false;
}
bool xl(char a,char b){
	if(a=='D' && b=='F') return true;
	if(a=='F' && b=='D') return true;
	if(a=='A' || a=='B' || a=='C'){
		if(b==a-1 || b==a+1){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>co>>so>>ct>>st;
	if(co==ct){
		cout<<"1";
		ff=true;
	}else{
		cout<<"0";
	}
	if(ff && so[0]==st[0] && so[1]==st[1]){
		cout<<"1";
		fs=true;
	}else{
		cout<<"0";
	}
	if(ff && fs && gd(so[2],st[2])){
		cout<<"1";
		ft=true;
	}else{
		cout<<"0";
	}
	if(ff && fs && ft && xl(so[2],st[2])){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}

