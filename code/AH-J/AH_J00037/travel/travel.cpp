#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F') return true;
		else return false;
	}else{
		if(b=='D'||b=='F') return false;
		else return true;
	}
}
bool check2(char a,char b){
	if(a=='A'&&b=='C') return false;
	if(a=='C'&&b=='A') return false;
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(check(b[2],d[2])) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(check2(b[2],d[2])){
		cout<<1;
	}else cout<<0;
	return 0;
}
