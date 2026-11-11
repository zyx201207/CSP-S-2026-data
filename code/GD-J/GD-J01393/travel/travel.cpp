#include<bits/stdc++.h>
using namespace std;
char c11,c12,s11,s12,s13,c21,c22,s21,s22,s23,ep;
int bl(char ch){
	if(ch=='A'||ch=='B'||ch=='C')return 1;
	return 2;
}
int xl(char x,char y){
	if(x=='A'&&y=='B')return 1;
	if(x=='B'&&y=='A')return 1;
	if(x=='B'&&y=='C')return 1;
	if(x=='C'&&y=='B')return 1;
	if(x=='D'&&y=='F')return 1;
	if(x=='F'&&y=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>c12;
	cin>>s11>>s12>>s13;
	cin>>c21>>c22;
	cin>>s21>>s22>>s23;
	if(c11==c21&&c12==c22){
		cout<<1;
		if(s11==s21&&s12==s22){
			cout<<1;
			if(bl(s13)==bl(s23)){
				cout<<1;
				if(xl(s13,s23))cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
} 
/*
02 01C 02 01A
*/
