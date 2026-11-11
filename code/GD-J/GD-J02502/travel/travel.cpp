#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a,b,c;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		a=1;
		cout<<"1";
	}
	else {
		a=0;
		cout<<"0";
	}
	if(a==1){
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
			b=1;
			cout<<"1";
		}
		else {
			b=0;
			cout<<"0";
		}
	}
	cout<<"0";
	if(a==1&&b==1){
		if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C' ) {
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C' ) {
				c=1;
				cout<<"1";
			}
			else {
				c=0;
				cout<<"0";
			}
		}
		else{
			if(s2[2]=='D' || s2[2]=='F'){
				c=2;
				cout<<"1"<<"1";
			}
			else {
				c=0;
				cout<<"0";
			}
		}
	}
	else cout<<"0";
	if(c!=2){
		if(a==1&&b==1){
			if(c==1){
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"0";
		}
		else cout<<"0";
	}
	return 0;
}
