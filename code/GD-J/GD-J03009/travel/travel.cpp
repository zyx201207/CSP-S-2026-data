#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main(){
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[1]==d[1]&&b[0]==d[0]){
			cout<<"1";
			if(b[2]<=67==d[2]<=67){
				cout<<"1";
				if(abs(b[2]-d[2])==1||(b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F')){
					cout<<"1";
				}else {
				cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}return 0;
} 
