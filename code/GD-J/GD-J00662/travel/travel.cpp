#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	getline(cin,s);
	string n,m,u,o;
	n=s.substr(0,2);
	m=s.substr(3,3);
	u=s.substr(7,2);
	o=s.substr(10,3);
	for(int i=0;i<=1;i++){
		if(n[i]!=u[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<=2;i++){
		if(i==2){
			if((m[i]>='A'&&m[i]<='C'&&o[i]>='D'&&o[i]<='F')||(o[i]>='A'&&o[i]<='C'&&m[i]>='D'&&m[i]<='F')){
				cout<<"1100";
				return 0;
			}
			if(m[i]=='A'&&o[i]!='B'){
				cout<<"1110";
				return 0;
			}
			if(m[i]=='B'&&(o[i]!='A'||o[i]!='C')){
				cout<<"1110";
				return 0;
			}
			if(m[i]=='C'&&o[i]!='B'){
				cout<<"1110";
				return 0;
			}
			if(m[i]=='D'&&o[i]!='F'){
				cout<<"1110";
				return 0;
			}
			if(m[i]=='F'&&o[i]!='D'){
				cout<<"1110";
				return 0;
			}
		}
		else if(m[i]!=o[i]){
			cout<<"1000";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
}
