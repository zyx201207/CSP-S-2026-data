#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,c1,a2,c2;
	cin>>a1>>c1>>a2>>c2;
	if(a1==a2){
		cout<<1;
	} 
	else{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0; 
	}
	int x=0,y=0;
	if(c1[2]=='A' || c1[2]=='B' || c1[2]=='C'){
		x=1;
	}
	if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C'){
		y=1;
	}
	if(x^y){
		cout<<"00";
		return 0;
	}
	else{
		cout<<1;
	}
	if(x==0){
		cout<<1;
		return 0;
	}
	if(c1[2]=='A' || c1[2]=='C'){
		x=1;
	}
	if(c2[2]=='A' || c2[2]=='C'){
		y=1;
	}
	if(x^y){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
