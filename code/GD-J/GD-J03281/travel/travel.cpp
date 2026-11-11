#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rs,xs;
	int rc,xc;
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		if(rs[1]-'0'==xs[1]-'0'){
			if((rs[2]<='C'&&xs[2]<='C')||(rs[2]>'C'&&xs[2]>'C')){
				if((rs[2]>'C'&&xs[2]>'C')||(rs[2]=='B'||xs[2]=='B')){
					cout<<1111;
				}else{
					cout<<1110;
					return 0;
				} 
			}
			else{
				cout<<1100;
				return 0;
			} 
		}
		else{
			cout<<1000;
			return 0;
		} 
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
