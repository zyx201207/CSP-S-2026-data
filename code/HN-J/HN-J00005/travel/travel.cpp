#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	int t=1;
	if(a1==a2) cout<<1;
	else{
		cout<<0;
		t=0;
	} 
	if(t&&b1[0]==b2[0]&&b1[1]==b2[1]){
		cout<<1;
	}
	else{
		cout<<0;
		t=0;
	}
	if(t&&(b1[2]<='C'&&b2[2]<='C')){
		cout<<1;
	}
	else{
		cout<<0;
		t=0;
	}
	if((b1[2]=='C'&&b2[2]=='D')||(b2[2]=='C'&&b1[2]=='D')){
		t=0;
	}
	else{
		t=1;
	}
	if(t&&(b2[2]-b1[2]==1||b1[2]-b2[2]==1)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
