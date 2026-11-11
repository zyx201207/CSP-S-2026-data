#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string seat[4];
	bool next=false;
	for(int i=0;i<4;i++){
		cin>>seat[i];
	}
	if(seat[0]==seat[2]){
		cout<<1;
		next=true;
	}
	else{
		cout<<"0000";
	}
	if(next){
		next=false;
		if(seat[1][0]==seat[3][0]&&seat[1][1]==seat[3][1]){
			cout<<1;
			next=true;
		}
		else{
			cout<<"000";
		}
	}
	bool ascii;
	if(next){
		next=false;
		ascii=(seat[1][2]>'C');
		if( (seat[3][2]>'C')==ascii ){
			cout<<1;
			next=true;
		}
		else{
			cout<<"00";
		}
	}
	if(next){
		if(ascii){
			cout<<1;
		}
		else if(-2<seat[1][2]-seat[3][2]&&seat[1][2]-seat[3][2]<2){
			cout<<1;
		} 
		else{
			cout<<0;
		}
	}
	return 0;
}
