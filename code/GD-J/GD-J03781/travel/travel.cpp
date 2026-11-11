#include<bits/stdc++.h>
using namespace std;
bool xianglin(char a,char b){
	if(a+1==b || b+1==a){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=0,b=0,c=0,d=0;
	if(c1==c2){
		a=1;	
	}
	
	//a
	
	
	if(s1[0]==s2[0] && s1[1]==s2[1] && a==1){
		b=1;
	}
	
	//b
	
	//01c 01d
	int yice[2];
	if(s1[2]>='A' && s1[2]<='C'){
		yice[1]=0; //s1 ABC
	}else{
		yice[1]=1; //s1 DF
	}
	if(s2[2]>='A' && s2[2]<='C'){
		yice[2]=0; //s2 ABC
	}else{
		yice[2]=1; //s2 DF
	}
	if(yice[1]==yice[2] && b==1){
		c=1;
	}
	
	
	//c
	
	
	if(c==1 && xianglin(s1[2],s2[2])){
		d=1;
	}
	
	
	cout<<a<<b<<c<<d;
	return 0;
}
