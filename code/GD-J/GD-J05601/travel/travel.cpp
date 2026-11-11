#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			if((b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D')||(b[2]<='C'&&d[2]<='C')){
				cout<<'1';
				if(abs(int(b[2]-d[2]))==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
