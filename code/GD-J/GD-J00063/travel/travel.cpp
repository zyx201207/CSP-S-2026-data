#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if (a1==b1){
		cout<<1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	if (a2[0]==b2[0] && a2[1]==b2[1]){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	int A=(a2[2]=='A' || a2[2]=='B' || a2[2]=='C');
	int B=(b2[2]=='A' || b2[2]=='B' || b2[2]=='C');
	if (A==B){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if (abs(a2[2]-b2[2])==1){
		cout<<1;
	}
	else {
		cout<<0;
	}
	return 0;
} 
