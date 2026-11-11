#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
string num1,num2;
char word1,word2;
bool check(char a,char b){
	return (a=='A'&&b=='B')||(a=='B'&&b=='C')||(b=='A'&&a=='B')||(b=='B'&&a=='C')||(a=='D'&&b=='F')||(b=='D'&&a=='F');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	word1=s1[2];
	word2=s3[2];
	num1+=s1[0];
	num1+=s1[1];
	num2+=s3[0];
	num2+=s3[1];
	if(num1==num2&&s==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(num1==num2&&s==s2){
		if((word1>='A'&&word2>='A'&&word1<='C'&&word2<='C')||(word1>='D'&&word2>='D'&&word1<='F'&&word2<='F')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(num1==num2&&s==s2){
		if(check(word1,word2)){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
