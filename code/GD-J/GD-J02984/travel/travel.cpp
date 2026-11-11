#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f1=1,f2=1,f3=1,f4=1,a=0,b=0;
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1[1]!=s3[1]){
		f1=0;
		f2=0;
		f3=0;
		f4=0;
	}
	if(f1==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<s2.length()-1;i++){
		if(s2[i]!=s4[i]){
			f2=0;
			f3=0;
			f4=0;
			break;
		}
	}
	if(f2==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		a=1;
	}
	else{
		a=2;
	}
	if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'){
		b=1;
	}
	else{
		b=2;
	}
	if(a==b&&f3==1){
		cout<<1;
	}
	else{
		f4=0;
		cout<<0;
	}
	if(a==2&&b==2&&f4==1){
		cout<<1;
	}
	else if(f4==1&&(s4[2]=='B'||s2[2]=='B')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
