#include<bits/stdc++.h>
using namespace std;
int main(){ 
	string c1,c2,c3,c4;
	int kg1=0,kg2=0,kg3=0,kg4=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		kg1=1;	
	}
	if(kg1==0) cout<<0;
	if(c2[0]==c4[0] && c2[1]==c4[1]){
		cout<<1;
		kg2=1;
	}
	if(kg2==0) cout<<0;
	if(((c2[2]>='A' && c2[2]<='C') && (c4[2]>='A' && c4[2]<='C')) || ((c2[2]=='D' || c2[2]=='F') && (c4[2]=='D' && c4[2]=='F'))){
		cout<<1;
		kg3=1;
	}
	if(kg3==0) cout<<0;
	if((c2[2]>='A' && c2[2]<='C') && (c4[2]>='A' && c4[2]<='C')){
		if(c2[2]-c4[2]==1 || c2[2]-c4[2]==-1){
			cout<<1;
			kg4=1;
		}
	}
	else if((c2[2]=='D' || c2[2]=='F') && (c4[2]=='D' && c4[2]=='F')){
		if(c2[2]-c4[2]==2 || c2[2]-c4[2]==-2){
			cout<<1;
			kg4=1;
		}
	}
	if(kg4==0) cout<<0;
	return 0;
} 
