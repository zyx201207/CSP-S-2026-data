#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2, b1, b2;
	cin>>a1>>b1>>a2>>b2;
	int Rcx, Rp, Rz, Xcx, Xp, Xz;
	Rcx=stoi(a1);
	Rp=stoi(b1.substr(0, 2));
	Rz=b1.back();
	Xcx=stoi(a2);
	Xp=stoi(b2.substr(0, 2));
	Xz=b2.back();
	if(Rcx==Xcx){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(Rcx==Xcx&&Rp==Xp){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(Rcx==Xcx&&Rp==Xp&&((Rz=='A'&&Xz=='B')||(Rz=='A'&&Xz=='C')||(Rz=='B'&&Xz=='C')||(Rz=='D'&&Xz=='F')||(Rz=='B'&&Xz=='A')||(Rz=='C'&&Xz=='A')||(Rz=='C'&&Xz=='B')||(Rz=='F'&&Xz=='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(Rcx==Xcx&&Rp==Xp&&((Rz=='A'&&Xz=='B')||(Rz=='B'&&Xz=='C')||(Rz=='D'&&Xz=='F')||(Rz=='B'&&Xz=='A')||(Rz=='C'&&Xz=='B')||(Rz=='F'&&Xz=='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
