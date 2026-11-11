#include <bits/stdc++.h>
using namespace std;
bool ch(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C'||b=='A') return true;
		else return false;
	}
	if(a=='B'){
		if(b=='B'||b=='C'||b=='A') return true;
		else return false;
	}
	if(a=='C'){
		if(b=='B'||b=='C'||b=='A') return true;
		else return false;
	}
	if(a=='D'){
		if(b=='E') return true;
		else return false;
	}
	if(a=='E'){
		if(b=='D') return true;
		else return false;
	}
	return true;
}
bool cht(char a,char b){
	if(a=='A'){
		if(b=='B') return true;
		else return false;
	}
	if(a=='B'){
		if(b=='C'||b=='A') return true;
		else return false;
	}
	if(a=='C'){
		if(b=='B') return true;
		else return false;
	}
	if(a=='D'){
		if(b=='E') return true;
		else return false;
	}
	if(a=='E'){
		if(b=='D') return true;
		else return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char tb=b[2],td=d[2];
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&ch(tb,td)) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&cht(tb,td)) cout<<1;
	else cout<<0;
	
	
	
	return 0;
}
