#include <bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
bool c=false,d=false,f=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<1;
	}
	else{
		c=true;
		cout<<0;
	}
	if(c){
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<1;
	}
	else{
		d=true;
		cout<<0;
	}
	if(d){
		cout<<0<<0;
		return 0;
	}
	if(s1[2]>='D'&&s3[2]>'D'){
		cout<<1;
	}
	else if(s1[2]<='C'&&s3[2]<'C'){
		cout<<1;
	}
	else{
		f=true;
		cout<<0;
	}
	if(f){
		cout<<0;
		return 0;
	}
	if(s1[2]+1==s3[2]||s1[2]-1==s3[2]){
		if(s1[2]=='C'){
			if(s3[2]!='D'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(s1[2]=='D'){
			if(s3[2]!='C'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<1;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
