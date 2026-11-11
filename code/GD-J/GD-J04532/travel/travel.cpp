#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;
	cin>>a>>b;
	cin>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int f=b[0]*10+b[1];
	int g=d[0]*10+d[1];
	if(f==g){
		cout<<"1";
		if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'){
			cout<<"1";	
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
		cout<<"0";
	}
	if(f+1==g||f-1==g&&b[2]==d[2]||b[2]+1==d[2]||b[2]-1==d[2]&&f==g){
		if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C'){
			cout<<"0"; 
		}else{	
			cout<<"1";
		}
	
	}else{
		cout<<"0";
	}
}
