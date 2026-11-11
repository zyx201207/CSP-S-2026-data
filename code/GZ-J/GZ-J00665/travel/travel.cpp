//GZ-J0065,六枝特区岩脚镇中学,周孝熔。
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		a=1;
	}
	else {
		cout<<'0';
		a=0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && a==1){
		cout<<'1';
		b=1;
	}
	else{
		cout<<'0';
		b=0;
	}
	if(s1[2]<='C' && s1[2]>='A' && s2[2]<='C' && s2[2]>='A' && b==1 && a==1){
		cout<<1;
	}
	else if(s1[2]<='F' && s1[2]>='D' && s2[2]<='F' && s2[2]>='D' && b==1 && a==1){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(s1[2]=='A' && s2[2]=='B'){
		c=1;
	} 
	else if(s1[2]=='B' && s2[2]=='A'){
		c=1;
	}
	else if(s1[2]=='C' && s2[2]=='B'){
		c=1;
	}
	else if(s1[2]=='B' && s2[2]=='C'){
		c=1;
	}
	else if(s1[2]=='F' && s2[2]=='D'){
		c=1;
	}
	else if(s1[2]=='D' && s2[2]=='F'){
		c=1;
	}
	else{
		c=0;
	}
	if(a==b==c==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
