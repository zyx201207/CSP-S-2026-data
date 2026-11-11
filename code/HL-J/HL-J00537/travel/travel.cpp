#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
string s1,s2;
char u1,u2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	a1=s1[0]*10+s1[1];
	a2=s2[0]*10+s2[1];
	if(a1==a2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	u1=s1[2];
	u2=s2[2];
	if((u1=='A'||u1=='B'||u1=='C')&&(u2=='A'||u2=='B'||u2=='C')){
		cout<<1;
	}else if((u1=='D'||u1=='F')&&(u2=='D'||u2=='F')){
		cout<<11;
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	
	if((u1=='A'&&u2=='B')||(u1=='B'&&u2=='A')||(u1=='B'&&u2=='C')||(u1=='C'&&u2=='B')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

