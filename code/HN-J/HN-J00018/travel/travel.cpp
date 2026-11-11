#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1,k;
void why(char a,char b){
	if(a=='A'){
		if(b-a<=2){
			k+='1';
		}
		else k+='0';
	}
	else if(a=='B'){
		if(b-a<=1){
			k+='1';
		}
		else k+='0';
	}
	else if(b=='F'&&a=='D') k+='1';
	else k+='0';
}
void why2(char a,char b){
	if(b<='C'){
		if(b-a==1) k+='1';
		else k+='0';
	}
	else if(b=='F'){
		if(a=='D') k+='1';
		else k+='0';
	}
	else k+='0';
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c[0]==c1[0]&&c[1]==c1[1]){
		k+='1';
		if(s[0]==s1[0]&&s[1]==s1[1]){
			k+='1';
			char s2=max(s[2],s1[2]),s3=min(s[2],s1[2]);
			why(s3,s2);
			why2(s3,s2);
		}
		else{
			k+='0';
			k+='0';
			k+='0';
		}
	}
	else{
		k+='0';
		k+='0';
		k+='0';
		k+='0';
	}
	cout<<k;
	return 0;
} 
