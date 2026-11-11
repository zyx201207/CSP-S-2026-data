#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool p1,p2,p3,p4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		p1=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)&&p1){
		p2=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s1[2]>'C')&&(s2[2]>'C')&&p2){
		p3=1;
		cout<<1;
	}
	else if((s1[2]<='C')&&(s2[2]<='C')&&p2){
		p3=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(abs(s1[2]-s2[2])==1&&p3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
