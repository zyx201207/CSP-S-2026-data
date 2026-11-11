#include <bits/stdc++.h>
using namespace std; 
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2){
		cout<<"0000";
	}
	if(a1==a2){
		cout<<"1";
		if(b1[0]==b2[0]&&b1[1]==b2[1]){
			cout<<"1";
			if(b1[3]<='C'&&b2[3]<='C'){
				cout<<"1";
				if(b1[3]=='B'&&b2[3]=='A'){
					cout<<"1";
				}
				if(b1[3]=='B'&&b2[3]=='C'){
					cout<<"1";
				}
				if(b1[3]=='C'&&b2[3]=='B'){
					cout<<"1";
				}
				if(b1[3]=='A'&&b2[3]=='B'){
					cout<<"1";
				}
				if(b2[3]=='B'&&b1[3]=='A'){
					cout<<"1";
				}
				if(b2[3]=='B'&&b1[3]=='C'){
					cout<<"1";
				}
				if(b2[3]=='A'&&b1[3]=='B'){
					cout<<"1";
				}
				if(b2[3]=='C'&&b1[3]=='B'){
					cout<<"1";
				}
				if(b1[3]=='D'&&b2[3]=='E'){
					cout<<"1";
				}
				if(b1[3]=='E'&&b2[3]=='D'){
					cout<<"1";
				}
				else{
					cout<<"1";
				}
			}
			else{
				cout<<"0";
			}
			if(b1[3]=='D'&&b2[3]<'D'){
				cout<<"0";
			}
			if(b2[3]=='D'&&b1[3]<'D'){
				cout<<"0";
			}
			if(b1[3]=='E'&&b2[3]<'D'){
				cout<<"0";
			}
			if(b2[3]=='E'&&b1[3]<'D'){
				cout<<"0";
			}
		}
		else{
			cout<<"000";
		}
	}
	
	return 0;
}
//||是或  &&是与 
