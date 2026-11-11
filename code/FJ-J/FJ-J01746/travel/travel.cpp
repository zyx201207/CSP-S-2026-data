#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,a1,b1;
string a2,b2;
signed main(){
	cin>>a>>a2>>b>>b2;
	if(a2[0]=='0'){
		a1=a2[1]-'0';
	}else{
		a1=10+a2[1]-'0';
	}
	if(b2[0]=='0'){
		b1=b2[1]-'0';
	}else{
		b1=10+b2[1]-'0';
	}
	if(a==b){
		if(a1==b1){
			if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C')){
				if(a2[2]+1==b2[2]||a2[2]-1==b2[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
