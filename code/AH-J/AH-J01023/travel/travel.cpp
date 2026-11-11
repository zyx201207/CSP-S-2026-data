#include<bits/stdc++.h>
using namespace std;
string cx1,cx2;
string zw1,zw2;
bool sm(char a,char b){
	if(a<='C'&&b<='C'){
		return 1;
	}
	if(a>'C'&&b>'C'){
		return 1;
	}
	return 0;
}
bool xl(char a,char b){
	if(abs(a-b)==1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1;
	cin>>cx2>>zw2;
	if(cx1==cx2){
		//cout<<1;
		string t1=zw1.substr(0,2);
		string t2=zw2.substr(0,2);
		char c1=zw1[2];
		char c2=zw2[2];
		if(t1==t2){
			//cout<<1;
			if(sm(c1,c2)){
				//cout<<1;
				if(xl(c1,c2)){
					cout<<1111;
				}else{
					cout<<1110;
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
