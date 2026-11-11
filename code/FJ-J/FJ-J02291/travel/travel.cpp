#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",0);
	freopen("travel.out","w",0);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;}
	int q=int(b[0]-'0')*10+int(b[1]-'0'),w=int(d[0]-'0')*10+int(d[1]-'0'),e=int(b[2]-'A'),r=int(d[2]-'A');
	if(q!=w){
		cout<<1000;
		return 0;}
	if(((0<=e&&e<=2)&&(0<=r&&r<=2))||((3<=e&&e<=5)&&(3<=r&&r<=5))){
		if(abs(e-r)==1||(e==3||r==3))
			cout<<1111;
		else
			cout<<1110;
	}else
		cout<<1100;
	return 0;}