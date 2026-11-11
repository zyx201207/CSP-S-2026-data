#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	} else {
		cout<<"0000";
		return 0; 
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else {
		cout<<"000";
		return 0;
	}
	if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2] &&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<1;
			return 0;
		}else {
			cout<<0;
			return 0;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			cout<<1;
			return 0;
		}else {
			cout<<0;
			return 0;
		}
	}
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout<<1;
			return 0;
		}else {
			cout<<0;
			return 0;
		}
	}
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<1;
			return 0;
		}else {
			cout<<0;
			return 0;
		}
	}
	if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<1;
			return 0;
		}else {
			cout<<0;
			return 0;
		}
	}
	return 0;
}
