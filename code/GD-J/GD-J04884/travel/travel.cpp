#include<bits/stdc++.h>
using namespace std;
string n1,n2,m1,m2;
int main(){
	cin>>n1>>m1>>n2>>m2;
	if(n1[1]!=n2[1]){
		cout<<"0000";
	}else if(m1[1]!=m2[1]){
		cout<<"1000";
	}else if(
	(m1[2]>='A'&&m1[2]<='C')
	&&(m2[2]>='D'&&m2[2]<='F')||
	(m1[2]>='D'&&m1[2]<='F')
	&&(m2[2]>='A'&&m2[2])<='C'
	){
		cout<<"1100";
	}else if(abs(m1[2]-m2[2])!=1){
		cout<<"1110";
	}else cout<<"1111";
	return 0;
} 
