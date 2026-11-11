#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool g=0;
void check1(string x,string y){
	if(x==y) {cout<<1; return;  }
	else {cout<<0; g=1;}
}
void check2(string x,string y){
	if(g==1) {cout<<0; return;}
	if(x[0]==y[0]&&x[1]==y[1]) {cout<<1; return;}
	else {cout<<0; g=1;}
}
void check3(string x,string y){
	if(g==1){ cout<<0; return;}
	if(x[2]<='C'&&y[2]<='C') {cout<<1; return;}
	else {
		if(x[2]>='D'&&y[2]>='D'){ cout<<1; return;}
		else {cout<<0; g=1;}
	}
}
void check4(string x,string y){
	if(g==1) {cout<<0; return;}
	if(abs(x[2]-y[2])==1) {cout<<1; return;}
	else cout<<0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	check1(c1,c2);
	check2(s1,s2);
	check3(s1,s2);
	check4(s1,s2);
}
