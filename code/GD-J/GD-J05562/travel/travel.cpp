#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int f=0,f1=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
		if((a2[2]=='F'||a2[2]=='D')&&(b2[2]=='F'||b2[2]=='D')){
			cout<<11;
		}else f1=0;
		if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')){
			cout<<1;
		}else f1=0;
		if(f1==0) cout<<0;
	}else{
		cout<<"000";
		return 0;
	}
	if(a2[2]=='C'){
		if(b2[2]=='B') f=1;
	}
	if(a2[2]=='B'){
		if(b2[2]=='C'||b2[2]=='A') f=1;
	}
	if(a2[2]=='A'){
		if(b2[2]=='B') f=1;
	}
	cout<<f;
	return 0;
} 

