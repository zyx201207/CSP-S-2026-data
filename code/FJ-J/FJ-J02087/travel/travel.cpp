#include<bits/stdc++.h>
using namespace std;
int R_c,X_c;
string R_s,X_s,R_w,X_w,R_h,X_h;
bool p;
bool pd(string x,string y){
	
	if((x>="A"&&x<="C")&&(y>="A"&&y<="C")){
		p=1;
		return true;
	}
	else if((x>="D"&&x<="F")&&(y>="D"&&y<="F")){
		p=0;
		return true;
	}
	else{
		return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>R_c>>R_s>>X_c>>X_s;
	if(R_c==X_c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		exit(0);
	}
	R_w=R_s.substr(0,2);
	X_w=X_s.substr(0,2);
	if(R_w==X_w){
		cout<<"1";
	}
	else{
		cout<<"000";
		exit(0);
	}
	R_w=R_s.substr(2,1);
	X_w=X_s.substr(2,1);
	if(pd(R_w,X_w)){
		if(!p){
			cout<<"11";
			exit(0);
		}
		else cout<<"1";
	}
	else{
		cout<<"00";
		exit(0);
	}
	if(((R_w=="A"&&X_w=="B")||(R_w=="B"&&X_w=="C")||(X_w=="A"&&R_w=="B")||(X_w=="B"&&R_w=="C"))&&p){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
