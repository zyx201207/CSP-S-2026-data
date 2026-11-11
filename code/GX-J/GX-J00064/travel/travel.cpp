#include<bits/stdc++.h>
using namespace std;
bool awa(char x,char y){
	if(x=='A'||x=='B'||x=='C'){
		if(y=='A'||y=='B'||y=='C'){
			return true;
		}
	}
	if(x=='D'||x=='F'){
		if(y=='D'||y=='F'){
			return true;
		}
	}
	return false;
}
bool qwq(char x,char y){
	if(x=='A'){
		if(y=='B'){
			return true;
		}
	}
	if(x=='B'){
		if(y=='A'||y=='C'){
			return true;
		}
	}
	if(x=='C'){
		if(y=='B'){
			return true;
		}
	}
	if(x=='D'){
		if(y=='F'){
			return true;
		}
	}
	if(x=='F'){
		if(y=='D'){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(awa(rs[2],xs[2])){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(qwq(rs[2],xs[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
