#include<bits/stdc++.h>
using namespace std;
char a1,b1;
int a,b,aa,bb;
bool p1=0,p2=0,p3=0,p4=0;
bool pan(char x,char y){
	if((x>='A'&&x<='C'&&y>='A'&&y<='C') || ((x=='D'||x=='F')&&(y=='D'||y=='F'))){
		return 1;
	}
	return 0;
}
int va,vb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>a1>>b>>bb>>b1;
	if(a1=='A'){
		va=1;
	}else if(a1=='B'){
		va=2;
	}else if(a1=='C'){
		va=3;
	}else if(a1=='D'){
		va=5;
	}else{
		va=6;
	}
	
	if(b1=='A'){
		vb=1;
	}else if(b1=='B'){
		vb=2;
	}else if(a1=='C'){
		vb=3;
	}else if(a1=='D'){
		vb=5;
	}else{
		vb=6;
	}
	
	if(a==b){
		p1=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(aa==bb){
		p2=1;
	}else{
		cout<<"1000";
		return 0;
	}
	if(pan(a1,b1)){
		p3=1;
	}else{
		cout<<"1100";
		return 0;
	}
	if(abs(va-vb)==1){
		p4=1;
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
//¹À·Ö:100 
