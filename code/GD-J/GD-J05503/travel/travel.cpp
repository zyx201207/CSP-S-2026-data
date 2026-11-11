#include<bits/stdc++.h>
using namespace std;
string s;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[5]=='F'){
		s[5]='E';
	}
	if(s[12]=='F'){
		s[12]='E';
	}
	if((s[0]-48)*10+(s[1]-48)==(s[7]-48)*10+(s[8]-48)){
		cout<<"1";
		if((s[3]-48)*10+(s[4]-48)==(s[10]-48)*10+(s[11]-48)){
			cout<<"1";
			if(((s[5]-64)<=3&&(s[12]-64)<=3)||((s[5]-64)>3&&(s[12]-64)>3)){
				cout<<"1";
				if(abs((s[5]-64)-(s[12]-64))<=1){
					cout<<"1";
				}else{
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
	}
	return 0;
}
