#include<iostream>
using namespace std;
int main(){
	sreopen("travel.in","w",std.in);
	sreopen("travel.out","r",std.out);
	long long bi=0,pi=0;
	string a,b,c,d;
	cin >> a >> b >>c >>d;
	if(a==c){
		cout << "1";
	}else{
		for(int i=1;i<=4;i++){
			cout << "0";
		}
		return 0;
	}
	if(b[0]==d[0] && b[1]==d[1]){
		cout << "1";
	}else{
		for(int i=1;i<=3;i++){
			cout << "0";
		}		
		return 0; 
	}
	if(b[2]=='A' || b[2]=='B' || b[2]=='C'){
		bi=1;
	}
	if(b[2]=='D' || b[2]=='E'){
		bi=2;
	}
	if(d[2]=='A' || d[2]=='B' || d[2]=='C'){
		pi=1;
	}
	if(d[2]=='D' || d[2]=='E'){
		pi=2;
	}
	if(pi==bi){
		cout << "1";
	}else{
		cout << "0";
		cout << "0";
		return 0;
	}
	if(d[2]+1==b[2] || d[2]-1==b[2]){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
} 
