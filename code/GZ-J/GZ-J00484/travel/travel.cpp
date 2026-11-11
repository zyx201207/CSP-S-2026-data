#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	int a2=(a1[1]-'0')*10+(a1[0]-'0');
	int b2=(b1[1]-'0')*10+(b1[0]-'0');
	
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a2!=b2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')){
		cout<<1;
		if(a1[2]=='A'&&b1[2]=='B'){
			cout<<1;
			return 0;
		}
		if(a1[2]=='B'&&(b1[2]=='A'||b1[2]=='C')){
			cout<<1;
			return 0;
		}
		if(a1[2]=='C'&&b1[2]=='B'){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}else if((a1[2]=='D'||a1[2]=='F')&&(b1[2]=='D'||b1[2]=='F')){
		cout<<1;
		if(a1[2]=='D'&&b1[2]=='F'){
			cout<<1;
			return 0;
		}
		if(a1[2]=='F'&&b1[2]=='D'){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<"00";
	return 0;
}
