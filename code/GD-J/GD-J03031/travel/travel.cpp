#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<s1.size()-1;i++){
		num1+=s1[i];
	}
	for(int i=0;i<s2.size()-1;i++){
		num2+=s2[i];
	}
	if(num1==num2&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	char x=s1[(int)s1.size()-1];
	char y=s2[(int)s2.size()-1];
	
	if(num1==num2&&c1==c2){
		if((x>='A'&&x<='C'&&(y>='A'&&y<='C') || (x>='D'&&x<='F'&&y>='D'&&y<='F'))){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(num1==num2&&c1==c2&&(y>='A'&&y<='C') || (x>='D'&&x<='F'&&y>='D'&&y<='F')){
		if((x=='A'&&y=='B') || (y=='A'&&x=='B')){
			cout<<1;
		}else if(x=='B'&&(y=='C'||y=='A') || (y=='B'&&(x=='C'||x=='A'))){
			cout<<1;
		}else if(x=='D'&&y=='F' || (y=='D'&&x=='F')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
}
/*

02 01A 02 01B













*/
