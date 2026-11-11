#include<bits/stdc++.h>
using namespace std;
bool k1(string m,string n){
	if(m[0]==n[0]&&m[1]==n[1]) return true;
	else return false;
}
bool k2(string m,string n){
	if(m[2]=='A'||m[2]=='B'||m[2]=='C'){
		if(n[2]=='A'||n[2]=='B'||n[2]=='C') return true;
		else return false;
	}
	else {
		if(n[2]=='D'||n[2]=='E') return true;
		else return false;
	}
}
bool k3(string m,string n){
	if(m[2]=='A'&&n[2]=='B') return true;
	else return false;
	
	if(m[2]=='B'&&(n[2]=='A'||n[2]=='C')) return true;
	else return false;
	
	if(m[2]=='C'&&n[2]=='B') return true;
	else return false;
	
	if(m[2]=='D'&&n[2]=='E') return true;
	else return false;
	
	if(m[2]=='E'&&n[2]=='D') return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c) {
		cout<<"0000";
		return 0;
	}else cout<<1;
	
	if(k1(b,d))cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	
	if(k2(b,d)) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	
	if(k3(b,d)) cout<<1;
	else cout<<0;
	return 0;
}


