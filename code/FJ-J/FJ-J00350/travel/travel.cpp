#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char h1,h2;
	cin>>c1>>s1>>h1>>c2>>s2>>h2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1!=s2){
		cout<<1000;
		return 0;
	}
	if((h1<='C'&&h2>='D')||(h2<='C'&&h1>='D')){
		cout<<1100;
		return 0;
	}
	if((h1=='C'&&h2=='A')||(h2=='C'&&h1=='A')){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
} 
