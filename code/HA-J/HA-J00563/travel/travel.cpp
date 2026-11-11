#include<bits/stdc++.h>
using namespace std;
bool cx(string a,string b){
	if (a==b){
		return 1;
	}
}
bool sz(string a,string b){
	if (a[0]==b[0] && a[1]==b[1]){
		return 1;
	}
	return 0;
}
bool cf(string a,string b){
	if (a[2]=='A' or a[2]=='B' or a[2]=='C'){
		if (b[2]=='A' or b[2]=='B' or b[2]=='C'){
			return 1;
		}
	}
	if (a[2]=='D' or a[2]=='F'){
		if (b[2]=='D' or b[2]=='F'){
			return 1;
		}
	}
	return 0;
}
bool xl(string a,string b){
	if (a[2]+1==b[2] or a[2]-1==b[2]){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	for (int i=0;i<4;i++){
		cin>>a[i];
	}
	if (cx(a[0],a[2])==0){
		cout<<"0000"<<"\n";
		return 0;
	}
	if (sz(a[1],a[3])==0){
		cout<<"1000"<<"\n";
		return 0;
	}
	if (cf(a[1],a[3])==0){
		cout<<"1100"<<"\n";
		return 0;
	}
	if (xl(a[1],a[3])==0){
		cout<<"1110"<<"\n";
		return 0;
	}
	cout<<"1111"<<"\n";
	return 0;
}
