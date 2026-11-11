#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,s1,s2;
int a,b,f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<2;i++){
		s1+=c2[i];
		s2+=c4[i];
	}
	a=c2[2]-'A';
	b=c4[2]-'A';
	if(c1==c3&&f==1){
		cout<<'1';
	}else {
		f=0;
		cout<<'0'; 
	}
	if(s1==s2&&f==1){
		cout<<'1';
	}else {
		f=0;
		cout<<'0';
	}
	if(((a<3&&b<3)||(a>=3&&b>=3))&&f==1){
		cout<<'1';
	}else {
		f=0;
		cout<<'0';
	}
	if((a+1==b||a-1==b)&&f==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
} 
