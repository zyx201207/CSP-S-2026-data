#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool pai=false,ce=false,xiang=false;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1,b1,a2,b2;
	if(c1==c2){
		xiang=true;
	}
	if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
		pai=true;
	}
	if(s1[2]>'C'&&s2[2]>'C'){
		ce=true;
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		ce=true;
	}
	if(xiang==true){
		cout<<1;
	}
	else cout<<0;
	if(xiang==true&&pai==true){
		cout<<1;
	}
	else cout<<0;
	if(xiang==true&&pai==true&&ce==true){
		cout<<1;
	}
	else cout<<0;
	if(xiang==true&&pai==true&&(s1[2]>'C'&&s2[2]>'C')){
		cout<<1;
	}
	else if(xiang==true&&pai==true&&(s1[2]<='C'&&s2[2]<='C')&&(abs(s1[2]-s2[2])==1)){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
