#include<bits/stdc++.h>
using namespace std;

string a1,b1,b2,a2;
int r,x;
char rr,xx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i = 0 ; i < b1.size() ; i ++){
		while(isdigit(b1[i])){
			r=r*10+(b1[i]-'0');
			i++;
		}
		if(!isdigit(b1[i])){
			rr=b1[i];
		}
	}
	for(int i = 0 ; i < b2.size() ; i ++){
		while(isdigit(b2[i])){
			x=x*10+(b2[i]-'0');
			i++;
		}
		if(!isdigit(b2[i])){
			xx=b2[i];
		}
	}	
	if(x==r){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(xx=='A'){
		if(rr=='B'||rr=='C')
		cout<<1;
	}
	else if(xx=='B'){
		if(rr=='A'||rr=='C')
		cout<<1;
	}
	else if(xx=='C'){
		if(rr=='B'||rr=='A')
		cout<<1;
	}
	else if((xx=='D'||xx=='F')&&(rr=='D'||rr=='F')){
		cout<<11;
		return 0; 			
	}
	else{
		cout<<00;
	}
	
	
	if((xx=='A'&&rr=='B')||(xx=='B'&&rr=='C')||(xx=='B'&&rr=='A')||(xx=='C'&&rr=='B')){
		cout<<1;		
	}
	else{
		cout<<0;
	}
	return 0;
}
