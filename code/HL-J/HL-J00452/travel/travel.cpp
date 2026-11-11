#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char z1,z2;
	cin>>c1>>s1>>z1>>c2>>s2>>z2;
	if(c1==c2){
		cout<<'1';
	}
	else if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<'1';
	}
	else if(s1!=s2){
		cout<<"000";
		return 0;
	}
	if(z1=='D' && z2=='F'){
		cout<<'1';
	}
	else if(z1=='F' && z2=='D'){
		cout<<'1';
	}
	else if(z1=='A' && z2=='B'){
		cout<<'1';
	}
	else if(z1=='A' && z2=='C'){
		cout<<'1';
	}
	else if(z1=='B' && z2=='A'){
		cout<<'1';
	}
	else if(z1=='B' && z2=='C'){
		cout<<'1';
	}
	else if(z1=='C' && z2=='A'){
		cout<<'1';
	}
	else if(z1=='C' && z2=='B'){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	int a=int(z1);
	int b=int(z2);
	if(a-1==b || a+1==b){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
