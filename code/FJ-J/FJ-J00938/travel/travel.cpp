#include<bits/stdc++.h> 
using namespace std;
string c1,c2,s1,s2;
int a,b,a1,b1;
char r,x;
string str;
int number(char ch){
	return ch-'A'+1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	r=s1[2];
	x=s2[2];
	for(int i=0;i<c1.length();i++){
		a=a*10+(c1[i]-'0');
	}
	for(int i=0;i<2;i++){
		b=b*10+(s1[i]-'0');
	}
	for(int i=0;i<c2.length();i++){
		a1=a1*10+(c2[i]-'0');
	}
	for(int i=0;i<2;i++){
		b1=b1*10+(s2[i]-'0');
	}
	//
	if(a==a1){
		str=str+'1';
	}
	else{
		str=str+'0';
	}
	//
	if(a==a1&&b==b1){
		str=str+'1';
	}
	else{
		str=str+'0';
	}
	//
	if(a==a1&&b==b1&&(number(r)<=3&&number(x)<=3||number(r)>3&&number(x)>3)){
		str=str+'1';
	}
	else{
		str=str+'0';
	}
	//
	if(a==a1&&b==b1){
		if(number(r)<=3&&number(x)<=3){
			if(abs(number(r)-number(x))==1){
				str=str+'1';
			}
			else str=str+'0';
		}
		else if(number(r)>3&&number(x)>3){
			str=str+'1';
		}
		else{
			str=str+'0';
		}
	}
	else{
		str=str+'0';
	}
	cout<<str;
	return 0;
}
