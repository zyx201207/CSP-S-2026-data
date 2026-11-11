#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
	} else{
		cout<<0<<0<<0<<0;
		return 0;
	}if(b1[1]==b2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
			cout<<1;
		}
	}else{
		cout<<0<<0;
		return 0;
	}
	if(b1[2]=='F'||b1[2]=='D'){
		if(b2[2]=='F'||b2[2]=='D'){
			cout<<1;
		}
	}else{
		cout<<0<<0;
		return 0;
	}if(b1[2]=='F'||b1[2]=='D'||b1[2]=='B'||b2[2]=='B'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
