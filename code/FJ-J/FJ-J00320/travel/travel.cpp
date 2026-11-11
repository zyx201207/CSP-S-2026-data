#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[1]!=c[1]){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C' && d[2]<='C'|| b[2]>'C' && d[2]>'C'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
